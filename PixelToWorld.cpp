#include "PixelToWorld.h"

#include <cmath>
#include <vector>

#include <opencv2/calib3d.hpp>

namespace
{
double dot3(const std::array<double, 3>& a,
            const turret_kinematics::Translation3d& b)
{
    return a[0] * b.X().value() + a[1] * b.Y().value() + a[2] * b.Z().value();
}

double norm3(const std::array<double, 3>& v)
{
    return std::sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}
} // namespace

PixelToWorldConfig::PixelToWorldConfig()
    : fx(1300.0),
      fy(1300.0),
      cameraInGimbal{
          turret_kinematics::Translation3d{0.0, 0.0, 0.0},
          turret_kinematics::Rotation3d::FromDegrees(-90.0, 0.0, -90.0)},
      gimbalOriginInWorld{0.0, 0.0, 0.0},
      targetPlaneNormalWorld{1.0, 0.0, 0.0},
      targetPlanePointWorld{2.0, 0.0, 0.0},
      yawOffset{0.0},
      pitchOffset{0.0},
      yawSign(1.0),
      pitchSign(1.0),
    requireIntersectionInFront(true)
{
}

PixelToWorld::PixelToWorld(const PixelToWorldConfig& config)
    : config_(config)
{
}

void PixelToWorld::setConfig(const PixelToWorldConfig& config)
{
    config_ = config;
}

const PixelToWorldConfig& PixelToWorld::config() const
{
    return config_;
}

PixelToWorldConfig& PixelToWorld::config()
{
    return config_;
}

std::optional<turret_kinematics::Translation3d> PixelToWorld::projectPixelToWorld(
    const cv::Point2d& pixel,
    const GimbalAngles& gimbalAngles) const
{
   return std::nullopt;
}

std::optional<cv::Point2d> PixelToWorld::worldToPixel(
    const turret_kinematics::Translation3d& point,
    const GimbalAngles& angles) const
{
    return std::nullopt;
}