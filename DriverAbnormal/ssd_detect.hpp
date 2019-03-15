#ifndef SSD_DETECT_HPP
#define SSD_DETECT_HPP




#ifndef _SSD_DETECT_HPP_
#define _SSD_DETECT_HPP_

#include "head.h"
#include <map>
class Detector {
    public:
        Detector();
        ~Detector();
        void Set(string model_file,  string weights_file,  string mean_file, string mean_value,  const int isMobilenet);

        std::vector<vector<float> > Detect(const cv::Mat& img);

    public:
        int* Postprocess_Face_CUP(cv::Mat& img, const float confidence_threshold, std::vector<vector<float> > detections,cv::Mat& FaceImg);
        int* Postprocess_Eye_SMOKE_YAWN(cv::Mat& Faceimg, const float confidence_threshold, std::vector<vector<float> > detections,std::map<int, cv::Mat>& EyeMap);

    private:
        void SetMean(const string& mean_file, const string& mean_value);
        void WrapInputLayer(std::vector<cv::Mat>* input_channels);
        void Preprocess(const cv::Mat& img, std::vector<cv::Mat>* input_channels);
        std::string flt2str(float f);
        std::string int2str(int n) ;

    private:
        std::shared_ptr<Net<float> > net_;
        cv::Size input_geometry_;
        int num_channels_;
        cv::Mat mean_;
        float scale_;

        std::string CLASSES_FACE_CUP[4] = { "background", "face","cup" };
        std::string CLASSES_EYE_SMOKE_YAWN[4] = { "background", "eye","smoke","yawn"};
        std::string CLASSES_EYE_STATUS[4] = { "background","open","close"};
        //std::string CLASSES_SMOKE_YAWN[4] = { "background","smoke","yawn"};
};
#endif




#endif // SSD_DETECT_HPP
