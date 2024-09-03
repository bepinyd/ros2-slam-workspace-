from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
import os
from ament_index_python.packages import get_package_share_directory
from launch_ros.descriptions import ParameterValue
from launch.substitutions import  Command,LaunchConfiguration
def generate_launch_description():
    model=DeclareLaunchArgument(
        name="model",
        default_value=os.path.join(get_package_share_directory("new_robot_description"),"urdf","my_robot.xacro"),
        description="Default path for model"
    )
    robot_description=ParameterValue(Command(["xacro ", LaunchConfiguration("model")]),value_type=str)
    robot_state_publisher=Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[{"robot_description":robot_description}]
    )
    joint_satate_publisher=Node(
        package="joint_state_publisher_gui",
        executable="joint_state_publisher_gui"

    )
    rviz=Node(
        package="rviz2",
        executable="rviz2",
        output="screen",
        arguments=["-d",os.path.join(get_package_share_directory("new_robot_description"),"rviz","urdf_config.rviz")]
    )
    return LaunchDescription([
        model,robot_state_publisher,joint_satate_publisher,rviz

    ])