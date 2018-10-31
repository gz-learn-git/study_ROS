#include "talker.h"

RosTalker::RosTalker(){
    chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
}

void RosTalker::talk(int count){
    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);
}

int RosTalker::add(int a, int b){
    return a + b;
}

/*
int main(int argc, char **argv){
    ros::init(argc, argv, "talker");
    RosTalker rt;
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok()){
        rt.talk(count);
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
    return 0;
}
*/