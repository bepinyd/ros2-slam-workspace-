
#pragma once

#include <rclcpp/rclcpp.hpp>
#include <turtlesim/msg/pose.hpp>

class TurtlesimPose: public rclcpp::Node 
{
    public:
    TurtlesimPose(const std::string &name);

    private:
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr sub1_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr sub2_;
    void turtlecallback(const turtlesim::msg::Pose &pose);
    void turtle1callback(const turtlesim::msg::Pose &pose);
    turtlesim::msg::Pose last_pose_turtle1;
    turtlesim::msg::Pose last_pose_turtle2;
};

