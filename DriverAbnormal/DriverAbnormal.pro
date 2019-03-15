#-------------------------------------------------
#
# Project created by QtCreator 2018-12-23T19:29:00
#
#-------------------------------------------------

QT       += core gui
QT       += opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DriverAbnormal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ssd_detect.cpp \
    classifer.cpp

HEADERS  += mainwindow.h \
    ssd_detect.hpp \
    head.h \
    classifer.hpp

FORMS    += mainwindow.ui


LIBS += /usr/lib/x86_64-linux-gnu/libboost_date_time.a  \
        /usr/lib/x86_64-linux-gnu/libboost_system.a \
        -L/usr/local/lib -L/home/gjw/caffe-ssd-mobile/build/lib -L/usr/lib/x86_64-linux-gnu \
        -lopencv_highgui  -lopencv_core  -lopencv_imgproc  -lboost_system -lglog -lcaffe \
        -lprotobuf -lgflags -lswscale  -lboost_thread   -lpthread
INCLUDEPATH += \
            /usr/local/include \
            /usr/include/opencv \
            /usr/include/opencv2 \
            /home/gjw/caffe-ssd-mobile/include \
            /home/gjw/caffe-ssd-mobile/build/src \
            /usr/local/cuda-8.0/include    \
            /usr/include/boost/  \
/usr/lib/x86_64-linux-gnu
