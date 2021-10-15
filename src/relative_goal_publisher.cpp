#include "relative_goal_publisher/relative_goal_publisher.h"

RelativeGoalPublisher::RelativeGoalPublisher(void):private_nh("~")
{
    sub_odom_comp = private_nh.subscribe("/odom/complement", 1, &RelativeGoalPublisher::odom_complement_callback, this);
    sub_local_goal = private_nh.subscribe("/local_goal", 1, &RelativeGoalPublisher::local_goal_callback, this);

    pub_relative_goal = private_nh.advertise<geometry_msgs::PoseStamped>("/local_goal/relative", 1);

    odom_update_flag = false;
    local_goal_update_flag = false;
}

void RelativeGoalPublisher::odom_complement_callback(const nav_msgs::OdometryConstPtr& msg)
{
    odom_complement = *msg;
    odom_update_flag = true;
}

void RelativeGoalPublisher::local_goal_callback(const geometry_msgs::PoseStampedPtr& msg)
{
    local_goal = *msg;
    local_goal_update_flag = true;
}

void RelativeGoalPublisher::goal_recreator(const nav_msgs::Odometry odom, const geometry_msgs::PoseStamped goal)
{
    relative_goal = goal;

    relative_goal.pose.position.x = goal.pose.position.x - odom.pose.pose.position.x;
    relative_goal.pose.position.y = goal.pose.position.y - odom.pose.pose.position.y;
    relative_goal.pose.position.z = goal.pose.position.z - odom.pose.pose.position.z;
}

void RelativeGoalPublisher::process()
{
    ros::spin();
    if(odom_update_flag && local_goal_update_flag){
        goal_recreator(odom_complement, local_goal);
        odom_update_flag = false;
        local_goal_update_flag = false;
    }
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "relative_goal_publisher");
    RelativeGoalPublisher relative_goal_publisher;
    relative_goal_publisher.process();
    return 0;
}