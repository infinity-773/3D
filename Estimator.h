#ifndef ESTIMATOR_H
#define ESTIMATOR_H
#include "Model.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <deque>
#include <limits>
#include "Serial.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <atomic>
class CenterEstimator {
public:
    CenterEstimator( frc ::Translation3d perior ,double r):
    periorData(perior),
    expectedCenter(periorData),
    res(std::numeric_limits<double>::infinity()),
    lambda(0.5),
    huber(0.05),
    radius(r) {};

    void calc(frc::Translation3d targetInBase , double now){
       
    };

    

    frc::Translation3d getExpCenter() const {
        return expectedCenter;
    }

    double getRes() const {
        return res;
    }

    bool hasEnoughSamples() const {
        return targets.size() >= 3;
    }

    void reset()
    {
        targets.clear();
        expectedCenter = periorData;
        res = std::numeric_limits<double>::infinity();
    }


private:
    frc::Translation3d periorData{frc::Translation3d{2.0 , -0.07 , 0.275}};
    std::deque<frc::Translation3d> targets;
    frc::Translation3d expectedCenter;
    double res = 10; //几何残差
    double lambda = 0.3;
    double huber = 0.05;
    double radius = 0.0;

};




#endif // ESTIMATOR_H