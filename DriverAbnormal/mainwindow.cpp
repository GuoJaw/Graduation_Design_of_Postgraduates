#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ssd_detect.hpp"
#include "classifer.hpp"
#include <string.h>

#include <sstream>
#include <iostream>


/********************************************/

//Qt的label显示OpenCV的Mat图像
void LabelDisplayMat(QLabel *label, cv::Mat &mat)
{
    cv::Mat Rgb;
    QImage Img;
    if (mat.channels() == 3)//RGB Img
    {
        cv::cvtColor(mat, Rgb, CV_BGR2RGB);//颜色空间转换
        Img = QImage((const uchar*)(Rgb.data), Rgb.cols, Rgb.rows, Rgb.cols * Rgb.channels(), QImage::Format_RGB888);
    }
    else//Gray Img
    {
        Img = QImage((const uchar*)(mat.data), mat.cols, mat.rows, mat.cols*mat.channels(), QImage::Format_Indexed8);
    }
    Img = Img.scaled(label->size());//原图自适应label
    label->setPixmap(QPixmap::fromImage(Img));
}

// 判断眼睛状态，并显示,eyeStatueFlag is return_value
void JudgeEyeStatus(bool& eyeStatueFlag, Classifier& classifier, QLabel *label_Left_eye,QLabel *label_Right_eye,std::map<int,cv::Mat>& EyeMap)
{
    // show eye image on label
    if(EyeMap.size() == 2)  //如果检测到2只眼睛
    {
        LabelDisplayMat(label_Left_eye, EyeMap.begin()->second);
        LabelDisplayMat(label_Right_eye, (++(EyeMap.begin()))->second);
    }
    else
    {
        LabelDisplayMat(label_Left_eye, EyeMap.begin()->second);
    }

    for(std::map<int, cv::Mat>::iterator iter = EyeMap.begin();iter!=EyeMap.end();iter++)
    {
       std::vector<Prediction> predictions = classifier.Classify((iter->second));  //classifier.Classify(img);

       //二分类
       eyeStatueFlag = true;   // 默认true为睁眼

       if((predictions[0].second == 0.5 && predictions[1].second == 0.5 ) ||((predictions[0].second>0.8 && predictions[0].first == "close")))
       {
           eyeStatueFlag = false;
           break;
       }
       else if(predictions[0].second>0.8 && predictions[0].first == "open")
       {
           eyeStatueFlag = true;
       }
       else
       {
           eyeStatueFlag = false;
           break;
       }

    } //for

    if(eyeStatueFlag == false) //close
    {
        for(std::map<int,cv::Mat>::iterator iter = EyeMap.begin();iter!=EyeMap.end();iter++)
        {
            cv::putText(iter->second, "close", cv::Point(2,10), CV_FONT_HERSHEY_COMPLEX, 0.5, cv::Scalar(0,0,255), 1, 2);   //将分类结果画到图上
        }
    }
    else  //open
    {
        for(std::map<int,cv::Mat>::iterator iter = EyeMap.begin();iter!=EyeMap.end();iter++)
        {
            cv::putText(iter->second, "open", cv::Point(2,10), CV_FONT_HERSHEY_COMPLEX, 0.5, cv::Scalar(0,255,0), 1, 2);   //将分类结果画到图上
        }
    }
    EyeMap.clear();
}

/********************************************/

const int isMobilenet = 1;

DEFINE_string(mean_file, "", "The mean file used to subtract from the input image.");


#if isMobilenet
DEFINE_string(mean_value, "127", "If specified, can be one value or can be same as image channels"
    " - would subtract from the corresponding channel). Separated by ','."
    "Either mean_file or mean_value should be provided, not both.");
#else
DEFINE_string(mean_value, "104,117,123", "If specified, can be one value or can be same as image channels"
    " - would subtract from the corresponding channel). Separated by ','."
    "Either mean_file or mean_value should be provided, not both.");
#endif

DEFINE_string(file_type, "image", "The file type in the list_file. Currently support image and video.");
DEFINE_string(out_file, "result/out.txt", "If provided, store the detection results in the out_file.");
DEFINE_double(confidence_threshold, 0.7, "Only store detections with score higher than the threshold.");

string mean_file = FLAGS_mean_file;
string mean_value = FLAGS_mean_value;
string file_type = FLAGS_file_type;
string out_file = FLAGS_out_file;
float confidence_threshold = FLAGS_confidence_threshold;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int*     FaceCupArr = new int[2];
int*     EyeSmokeYawnArr = new int[3];
bool     eyeStatueFlag;


#define CHARTHEIGHT 60

// perclosV
float PERCLOSVALUE  = 0.15;  //set value

#define FRAME_COUNT   315  //以 FRAME_COUNT 帧为一个时间戳

int     roll_frame  = 0;  //统计当前已经走了多少帧，判断是否走完 FRAME_COUNT 帧
int     closeFrame  = 0;
double  perclosV = 0.0;

// 一次闭眼帧数
int ONCECLOSEFRAME = 30;  //set value

bool last_flag  = true;
int  stillcloseFrame = 0;


bool exitflag = false; //终止程序按钮

void MainWindow::on_pushButton_3_clicked()  //阈值设定
{
    PERCLOSVALUE   = ui->lineEdit_perclosvalue->text().toFloat();
    ONCECLOSEFRAME = ui->lineEdit_oncecloseframe->text().toInt();
}


//模型:face_cup
string model_file_face_cup = "../model/FaceCUP/MobileNetSSD_deploy.prototxt";
string weights_file_face_cup = "../model/FaceCUP/MobileNetSSD_final.caffemodel";

//模型:eye_smoke_ywan
string model_file_eye_smoke_yawn = "../model/eye_smoke_ywan/MobileNetSSD_deploy.prototxt";
string weights_file_eye_smoke_yawn = "../model/eye_smoke_ywan/MobileNetSSD_final.caffemodel";

//模型:Classify
string model_file_classifer   = "../model/GuoJaweeNet2/deploy.prototxt";
string trained_file_classifer = "../model/GuoJaweeNet2/caffe_GuojawNet__iter_10000.caffemodel";
string mean_file_classifer    = "../model/GuoJaweeNet2/mean.binaryproto";
string label_file_classifer   = "../model/GuoJaweeNet2/labels.txt";

// 加载网络:face_cup
Detector detector_face_cup;

// 加载网络:eye_smoke_yawn
Detector detector_eye_smoke_yawn;

// 加载网络: Classify
Classifier classifier;


cv::Mat HistogramChart(CHARTHEIGHT/2, FRAME_COUNT, CV_8UC3, cv::Scalar(255,255,255));
cv::Mat HistogramChartCLone(CHARTHEIGHT/2, FRAME_COUNT, CV_8UC3, cv::Scalar(255,255,255));

void MainWindow::on_pushButton_2_clicked()  //终止程序按钮
{
    exitflag = true;

    HistogramChartCLone.copyTo(HistogramChart);
    roll_frame = 0;
    closeFrame = 0;
    perclosV = 0.0;
}

void MainWindow::on_pushButton_loadweight_clicked()
{
    detector_face_cup.Set(model_file_face_cup, weights_file_face_cup, mean_file, mean_value, isMobilenet);
    detector_eye_smoke_yawn.Set(model_file_eye_smoke_yawn, weights_file_eye_smoke_yawn, mean_file, mean_value, isMobilenet);
    classifier.Set(model_file_classifer, trained_file_classifer, mean_file_classifer, label_file_classifer);
    ui->pushButton_loadweight->setEnabled(false);
}

void MainWindow::on_pushButton_clicked()
{
    exitflag = false;

    char lineEdit_perclosvalue_str[100];
    sprintf(lineEdit_perclosvalue_str,"%.2f",PERCLOSVALUE);
    ui->lineEdit_perclosvalue->setText(QString(lineEdit_perclosvalue_str));

    char lineEdit_oncecloseframe_str[100];
    sprintf(lineEdit_oncecloseframe_str,"%d",ONCECLOSEFRAME);
    ui->lineEdit_oncecloseframe->setText(QString(lineEdit_oncecloseframe_str));

    cv::VideoCapture cap(0);
    if (!cap.isOpened())
    {
        std::cout << "Failed to open video: " << std::endl;
    }

    cv::Mat img;
    double fps;
    double t = 0.0;


    while (true && exitflag == false)
    {
        //FPS：开始时间
        t = (double)cv::getTickCount();

        memset(FaceCupArr,0,sizeof(FaceCupArr));
        memset(EyeSmokeYawnArr,0,sizeof(EyeSmokeYawnArr));

        ui->lineEdit_smoke->setText(QString(" "));
        ui->lineEdit_drink->setText(QString(" "));
        ui->lineEdit_yawn->setText(QString(" "));
        ui->lineEdit_small_tired->setText(QString(" "));
        ui->lineEdit_big_tired->setText(QString(" "));

        if(roll_frame == FRAME_COUNT) //如果走完了一个轮回，就走下一个轮回：因此重置以下三个变量
        {
            HistogramChartCLone.copyTo(HistogramChart);
            roll_frame = 0;
            closeFrame = 0;
            perclosV = 0.0;
        }
        bool success = cap.read(img);

        cv::Mat kernel = (cv::Mat_<float>(3,3)<<0,-1,0,0,4,0,0,-1,0);
        cv::filter2D(img,img,CV_8UC3,kernel);

        if (!success)
        {
            break;
        }

        CHECK(!img.empty()) << "Error when read frame";
        roll_frame++;

        cv::Mat FaceImg;

        std::vector<vector<float> > detections_face_cup = detector_face_cup.Detect(img);
        FaceCupArr = detector_face_cup.Postprocess_Face_CUP(img, confidence_threshold, detections_face_cup,FaceImg);

        if (!FaceImg.empty())
        {
            // detect eye
            std::vector<vector<float> > detections_eye_smoke_yawn = detector_eye_smoke_yawn.Detect(FaceImg);
            std::map<int, cv::Mat> EyeMap;

            EyeSmokeYawnArr = detector_eye_smoke_yawn.Postprocess_Eye_SMOKE_YAWN(FaceImg, confidence_threshold, detections_eye_smoke_yawn,EyeMap);

            if(EyeSmokeYawnArr[0] == 1) //eye
            {
                JudgeEyeStatus(eyeStatueFlag, classifier, ui->label_Left_eye,ui->label_Right_eye,EyeMap);
            }

            if(EyeSmokeYawnArr[1] == 1)  //smoke
            {
                ui->lineEdit_smoke->setText(QString("yes"));
                ui->lineEdit_small_tired->setText(QString("yes"));
            }

            if(EyeSmokeYawnArr[2] == 1)  //yawn
            {
                ui->lineEdit_yawn->setText(QString("yes"));
                ui->lineEdit_big_tired->setText(QString("yes"));
            }
        }  //人脸

        if(eyeStatueFlag == false)
        {
            closeFrame++;
            if(last_flag == false)
            {
                stillcloseFrame++;
                if(stillcloseFrame > ONCECLOSEFRAME)
                {
                    ui->lineEdit_big_tired->setText(QString("yes"));
                }
            }
            last_flag = false;
            cv::line(HistogramChart,cv::Point(roll_frame,CHARTHEIGHT/4),cv::Point(roll_frame,CHARTHEIGHT),cv::Scalar(0,0,255),1);

        }
        else
        {
            if(last_flag == false)
            {
                std::string text = std::to_string(stillcloseFrame+1);
                cv::putText(HistogramChart,text,cv::Point(roll_frame,CHARTHEIGHT/3),cv::FONT_HERSHEY_SIMPLEX,0.2,cv::Scalar(0,0,0),0.01);//在图片上写文字
            }

            cv::line(HistogramChart,cv::Point(roll_frame,0),cv::Point(roll_frame,CHARTHEIGHT/4),cv::Scalar(0,255,0),1);

            last_flag = true;
            stillcloseFrame = 0;
        }

        //cv::imshow("HistogramChart",HistogramChart);
        //cv::waitKey(1);
        LabelDisplayMat(ui->label_HistogramChart, HistogramChart);

        perclosV = (double)closeFrame / FRAME_COUNT;
        char perclosStr[100];
        sprintf(perclosStr,"%.4f",perclosV);
        ui->lineEdit_perclos->setText(QString(perclosStr));  //将perclos值显示到edit上
        if(perclosV > PERCLOSVALUE)
        {
            ui->lineEdit_big_tired->setText(QString("yes"));
        }

        if(FaceCupArr[1] == 1)
        {
            ui->lineEdit_drink->setText(QString("yes"));
            ui->lineEdit_small_tired->setText(QString("yes"));
        }

        //FPS
        t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
        fps = 1.0 / t;
        char fpsStr[100];
        sprintf(fpsStr,"%.0f",fps);
        ui->lineEdit_fps->setText(QString(fpsStr));  //fps

        LabelDisplayMat(ui->label, img); //show image on label

        if((char)cv::waitKey(1) == 'q')
            break;
    } //while (true)

    if(cap.isOpened())
        cap.release();
}



