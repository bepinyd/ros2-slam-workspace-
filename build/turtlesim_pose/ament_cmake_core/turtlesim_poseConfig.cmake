# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_turtlesim_pose_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED turtlesim_pose_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(turtlesim_pose_FOUND FALSE)
  elseif(NOT turtlesim_pose_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(turtlesim_pose_FOUND FALSE)
  endif()
  return()
endif()
set(_turtlesim_pose_CONFIG_INCLUDED TRUE)

# output package information
if(NOT turtlesim_pose_FIND_QUIETLY)
  message(STATUS "Found turtlesim_pose: 0.0.0 (${turtlesim_pose_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'turtlesim_pose' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${turtlesim_pose_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(turtlesim_pose_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${turtlesim_pose_DIR}/${_extra}")
endforeach()
