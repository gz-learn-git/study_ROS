#ifndef ROS_TALKER_H
#define ROS_TALKER_H

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

class RosTalker{
public:
    RosTalker();
    ros::NodeHandle n;
    ros::Publisher chatter_pub;

    void talk(int count);
    int add(int a, int b);
};

#endif //ROS_TALKER_H