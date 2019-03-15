#ifndef CLASSIFER_H
#define CLASSIFER_H



#include "head.h"

/* Pair (label, confidence) representing a prediction. */
typedef std::pair<string, float> Prediction;

class Classifier {
public:
    Classifier(){}
    ~Classifier(){}
private:
    void SetMean(const string& mean_file);
    std::vector<float> Predict(const cv::Mat& img);
    void WrapInputLayer(std::vector<cv::Mat>* input_channels);
    void Preprocess(const cv::Mat& img,std::vector<cv::Mat>* input_channels);

public:
    void Set(const string& model_file,const string& trained_file,const string& mean_file, const string& label_file);
    std::vector<Prediction> Classify(const cv::Mat& img, int N = 5);

private:
    shared_ptr<Net<float> > net_;
    cv::Size input_geometry_;
    int num_channels_;
    cv::Mat mean_;
    std::vector<string> labels_;
};




#endif // CLASSIFER_H
