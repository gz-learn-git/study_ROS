#include <gtest/gtest.h>
#include <climits>
#include "talker.h"

TEST(TalkerTest, addTestShouldPass){
    RosTalker rt;
    ASSERT_EQ(4, rt.add(1, 3));
}

TEST(TalkerTest, addTestShouldFail){
    RosTalker rt;
    ASSERT_NE(INT_MAX, rt.add(1, INT_MAX));
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "tester");
    //ros::NodeHandle nh;
    return RUN_ALL_TESTS();
}