cmake_minimum_required(VERSION 2.8.3)
project(sample_vs_code)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  genmsg
  roscpp
  std_msgs
)

## Generate added messages and services with any dependencies listed here
generate_messages(
   DEPENDENCIES
   std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES sample_vs_code
#  CATKIN_DEPENDS genmsg roscpp std_msgs
#  DEPENDS system_lib
)

## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${GTEST_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/sample_vs_code.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
add_executable(talker src/talker.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(talker
   ${catkin_LIBRARIES}
)

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})

#############
## Testing ##
#############

find_package(rostest REQUIRED)

## Add gtest based cpp test target and link libraries
catkin_add_gtest(talker-test test/talker_test.cpp src/talker.cpp)
target_link_libraries(talker-test ${catkin_LIBRARIES})
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
