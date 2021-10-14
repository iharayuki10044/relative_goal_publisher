#include "relative_goal_publisher/relative_goal_publisher.h"

RelativeGoalPublisher::RelativeGoalPublisher(void):private_nh("~")
{
    sub_odom_comp = private_nh.subscribe("/odom/complement", 1, &RelativeGoalPublisher::odom_complement_callback, this);
}

void RelativeGoalPublisher::odom_complement_callback(const nav_msgs::OdometryConstPtr& msg)
{
    current_odom = *msg;
    odom_update_flag = true;
}

int main(int argc, char** argv)
{
    return 0;
}

void RelativeGoalPublisher::process()
{

}