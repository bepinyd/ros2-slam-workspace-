cmake_minimum_required(VERSION 3.8)
project(turtlesim_pose)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

find_package(turtlesim REQUIRED)
include_directories(include)

add_executable(turtlesim_pose_node src/turtlesim_pose.cpp)
ament_target_dependencies(turtlesim_pose_node rclcpp turtlesim)

install(TARGETS 
turtlesim_pose_node
DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY 
include 
DESTINATION include/${PROJECT_NAME})

if(BUILD_TESTING) 
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
