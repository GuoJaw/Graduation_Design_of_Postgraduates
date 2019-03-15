/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_yawn;
    QLabel *label_6;
    QLineEdit *lineEdit_perclos;
    QGroupBox *groupBox_2;
    QLineEdit *lineEdit_smoke;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_drink;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_small_tired;
    QLabel *label_7;
    QLabel *label_10;
    QLineEdit *lineEdit_big_tired;
    QLineEdit *lineEdit_fps;
    QLabel *label_3;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_Left_eye;
    QLabel *label_Right_eye;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_5;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_HistogramChart;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton_2;
    QLabel *label_14;
    QGroupBox *groupBox_6;
    QLineEdit *lineEdit_oncecloseframe;
    QLabel *label_15;
    QLineEdit *lineEdit_perclosvalue;
    QPushButton *pushButton_3;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *pushButton_loadweight;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1318, 905);
        MainWindow->setStyleSheet(QStringLiteral("font: 20pt \"Sans Serif\";"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1030, 670, 131, 81));
        pushButton->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"font: 14pt \"Sans Serif\";"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 831, 551));
        label->setStyleSheet(QLatin1String("border-width: 1px;\n"
"background-color: rgb(255, 145, 130);\n"
"border-style: solid;\n"
"border-color: rgb(0, 0, 0);"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(850, 360, 221, 121));
        groupBox->setStyleSheet(QStringLiteral("font: 14pt \"Sans Serif\";"));
        lineEdit_yawn = new QLineEdit(groupBox);
        lineEdit_yawn->setObjectName(QStringLiteral("lineEdit_yawn"));
        lineEdit_yawn->setGeometry(QRect(110, 80, 71, 31));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(60, 80, 41, 20));
        label_6->setStyleSheet(QStringLiteral("font: 10pt \"Sans Serif\";"));
        lineEdit_perclos = new QLineEdit(groupBox);
        lineEdit_perclos->setObjectName(QStringLiteral("lineEdit_perclos"));
        lineEdit_perclos->setGeometry(QRect(110, 40, 71, 31));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(1090, 360, 221, 121));
        groupBox_2->setStyleSheet(QStringLiteral("font: 14pt \"Sans Serif\";"));
        lineEdit_smoke = new QLineEdit(groupBox_2);
        lineEdit_smoke->setObjectName(QStringLiteral("lineEdit_smoke"));
        lineEdit_smoke->setGeometry(QRect(100, 40, 71, 31));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 40, 51, 31));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 80, 51, 21));
        lineEdit_drink = new QLineEdit(groupBox_2);
        lineEdit_drink->setObjectName(QStringLiteral("lineEdit_drink"));
        lineEdit_drink->setGeometry(QRect(100, 80, 71, 31));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(980, 500, 221, 121));
        groupBox_3->setStyleSheet(QStringLiteral("font: 14pt \"Sans Serif\";"));
        lineEdit_small_tired = new QLineEdit(groupBox_3);
        lineEdit_small_tired->setObjectName(QStringLiteral("lineEdit_small_tired"));
        lineEdit_small_tired->setGeometry(QRect(110, 40, 71, 31));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 40, 61, 31));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 80, 61, 31));
        lineEdit_big_tired = new QLineEdit(groupBox_3);
        lineEdit_big_tired->setObjectName(QStringLiteral("lineEdit_big_tired"));
        lineEdit_big_tired->setGeometry(QRect(110, 80, 71, 31));
        lineEdit_fps = new QLineEdit(centralWidget);
        lineEdit_fps->setObjectName(QStringLiteral("lineEdit_fps"));
        lineEdit_fps->setGeometry(QRect(80, 0, 41, 26));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 0, 71, 31));
        label_3->setStyleSheet(QLatin1String("\n"
"font: 14pt \"Sans Serif\";"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(880, 400, 71, 21));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_Left_eye = new QLabel(centralWidget);
        label_Left_eye->setObjectName(QStringLiteral("label_Left_eye"));
        label_Left_eye->setGeometry(QRect(900, 50, 161, 121));
        label_Left_eye->setStyleSheet(QLatin1String("background-color: rgb(0, 255, 255);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        label_Right_eye = new QLabel(centralWidget);
        label_Right_eye->setObjectName(QStringLiteral("label_Right_eye"));
        label_Right_eye->setGeometry(QRect(1120, 50, 161, 121));
        label_Right_eye->setStyleSheet(QLatin1String("background-color: rgb(0, 255, 255);\n"
"border-width: 1px;\n"
"border-style: solid;"));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(880, 0, 421, 191));
        groupBox_4->setStyleSheet(QStringLiteral("font: 16pt \"Sans Serif\";"));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 580, 851, 211));
        groupBox_5->setStyleSheet(QStringLiteral("font: 16pt \"Sans Serif\";"));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(810, 190, 54, 18));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(80, 190, 54, 18));
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(450, 190, 54, 18));
        label_HistogramChart = new QLabel(centralWidget);
        label_HistogramChart->setObjectName(QStringLiteral("label_HistogramChart"));
        label_HistogramChart->setGeometry(QRect(90, 630, 751, 141));
        label_HistogramChart->setStyleSheet(QLatin1String("border-width: 1px;\n"
"background-color: rgb(0, 255, 127);\n"
"border-style: solid;\n"
"border-color: rgb(0, 0, 0);"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 630, 81, 31));
        label_8->setStyleSheet(QStringLiteral("font: 11pt \"Sans Serif\";"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 740, 71, 21));
        label_9->setStyleSheet(QStringLiteral("font: 11pt \"Sans Serif\";"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1180, 670, 131, 81));
        pushButton_2->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"font: 14pt \"Sans Serif\";"));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(880, 250, 101, 21));
        label_14->setStyleSheet(QString::fromUtf8("PERCLOS\351\230\210\345\200\274"));
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(850, 210, 311, 121));
        groupBox_6->setStyleSheet(QStringLiteral("font: 14pt \"Sans Serif\";"));
        lineEdit_oncecloseframe = new QLineEdit(groupBox_6);
        lineEdit_oncecloseframe->setObjectName(QStringLiteral("lineEdit_oncecloseframe"));
        lineEdit_oncecloseframe->setGeometry(QRect(150, 80, 71, 31));
        label_15 = new QLabel(groupBox_6);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 70, 131, 41));
        label_15->setStyleSheet(QStringLiteral("font: 11pt \"Sans Serif\";"));
        lineEdit_perclosvalue = new QLineEdit(groupBox_6);
        lineEdit_perclosvalue->setObjectName(QStringLiteral("lineEdit_perclosvalue"));
        lineEdit_perclosvalue->setGeometry(QRect(150, 40, 71, 31));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(1190, 260, 91, 51));
        pushButton_3->setStyleSheet(QStringLiteral("font: 14pt \"Sans Serif\";"));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(1080, 280, 131, 41));
        label_16->setStyleSheet(QStringLiteral("font: 12pt \"Sans Serif\";"));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(1080, 240, 131, 41));
        label_17->setStyleSheet(QStringLiteral("font: 12pt \"Sans Serif\";"));
        pushButton_loadweight = new QPushButton(centralWidget);
        pushButton_loadweight->setObjectName(QStringLiteral("pushButton_loadweight"));
        pushButton_loadweight->setGeometry(QRect(880, 670, 131, 81));
        pushButton_loadweight->setStyleSheet(QLatin1String("font: 12pt \"Sans Serif\";\n"
"font: 14pt \"Sans Serif\";"));
        MainWindow->setCentralWidget(centralWidget);
        lineEdit_fps->raise();
        label_3->raise();
        label_2->raise();
        pushButton->raise();
        label->raise();
        layoutWidget->raise();
        groupBox->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        label_Left_eye->raise();
        label_Right_eye->raise();
        groupBox_4->raise();
        groupBox_5->raise();
        label_HistogramChart->raise();
        label_8->raise();
        label_9->raise();
        pushButton_2->raise();
        label_14->raise();
        groupBox_6->raise();
        pushButton_3->raise();
        label_16->raise();
        label_17->raise();
        pushButton_loadweight->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1318, 46));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\345\274\200\345\220\257\347\233\221\346\216\247", 0));
        label->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "\351\207\215\345\272\246\345\274\202\345\270\270\350\241\214\344\270\272\350\257\206\345\210\253\346\250\241\345\235\227", 0));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\345\223\210  \346\254\240</span></p></body></html>", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\350\275\273\345\272\246\345\274\202\345\270\270\350\241\214\344\270\272\350\257\206\345\210\253\346\250\241\345\235\227", 0));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\346\212\275  \347\203\237</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">  \345\226\235   \346\260\264</span></p></body></html>", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\351\242\204\350\255\246\346\250\241\345\235\227", 0));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\350\275\273\345\272\246\351\242\204\350\255\246</span></p></body></html>", 0));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">\351\207\215\345\272\246\351\242\204\350\255\246</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\263\273\347\273\237\345\270\247\347\216\207</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">PERCLOS</span></p></body></html>", 0));
        label_Left_eye->setText(QString());
        label_Right_eye->setText(QString());
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\347\234\274\347\235\233\346\243\200\346\265\213\346\250\241\345\235\227", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\347\234\274\347\235\233\347\212\266\346\200\201\345\233\276", 0));
        label_11->setText(QApplication::translate("MainWindow", "10s", 0));
        label_12->setText(QApplication::translate("MainWindow", "0s", 0));
        label_13->setText(QApplication::translate("MainWindow", "5s", 0));
        label_HistogramChart->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "  \347\235\201\347\234\274\347\212\266\346\200\201", 0));
        label_9->setText(QApplication::translate("MainWindow", "  \351\227\255\347\234\274\347\212\266\346\200\201", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "\347\273\210\346\255\242\347\233\221\346\216\247", 0));
        label_14->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:11pt;\">PERCLOS\351\230\210\345\200\274</span></p></body></html>", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\344\270\264\347\225\214\351\230\210\345\200\274\350\256\276\345\256\232", 0));
        label_15->setText(QApplication::translate("MainWindow", "<html><head/><body><p>\344\270\200\346\254\241\351\227\255\347\234\274\345\270\247\346\225\260\351\230\210\345\200\274</p></body></html>", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "\350\256\276\345\256\232", 0));
        label_16->setText(QApplication::translate("MainWindow", "<html><head/><body><p>25~35</p></body></html>", 0));
        label_17->setText(QApplication::translate("MainWindow", "<html><head/><body><p>0.13~0.17</p></body></html>", 0));
        pushButton_loadweight->setText(QApplication::translate("MainWindow", "\345\212\240\350\275\275\347\275\221\347\273\234\346\250\241\345\236\213", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\351\251\276\351\251\266\345\221\230\345\274\202\345\270\270\350\241\214\344\270\272\350\257\206\345\210\253\344\270\216\351\242\204\350\255\246\347\263\273\347\273\237", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
