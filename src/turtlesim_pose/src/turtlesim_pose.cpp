#include "turtlesim_pose/turtlesim_pose.hpp"


using  std::placeholders::_1;
TurtlesimPose::TurtlesimPose(const std::string &name) : Node(name)
{
    sub1_=create_subscription<turtlesim::msg::Pose>("/turtle1/pose",10,std::bind(&TurtlesimPose::turtlecallback,this,_1));
    sub2_=create_subscription<turtlesim::msg::Pose>("/turtle2/pose",10,std::bind(&TurtlesimPose::turtle1callback,this,_1));

}

void TurtlesimPose::turtlecallback(const turtlesim::msg::Pose &pose){
last_pose_turtle1=pose;

}
void TurtlesimPose::turtle1callback(const turtlesim::msg::Pose &pose){
last_pose_turtle2=pose;
auto TX=last_pose_turtle2.x-last_pose_turtle1.x;
auto TY=last_pose_turtle2.y-last_pose_turtle1.y;
RCLCPP_INFO_STREAM(get_logger(),"THE TX VALUE IS : " << TX << "\n" << " TY: "<< TY << "\n");

}

int main(int argc, char* argv[]){
    rclcpp::init(argc,argv);
    auto node=std::make_shared<TurtlesimPose>("Turtle1");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}