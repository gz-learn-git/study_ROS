//#include "include/talker.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <gtest/gtest.h>

TEST(TestSuite, testCase1){
    ASSERT_FALSE(false);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "tester");
    ros::NodeHandle nh;
    return RUN_ALL_TESTS();
}