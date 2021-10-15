#ifndef __RELATIVE_GOAL_PUBLISHER_H
#define __RELATIVE_GOAL_PUBLISHER_H

#include <random>
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Pose.h>

#include <tf2_eigen/tf2_eigen.h>
#include <tf2/utils.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>

// Eigen
#include <Eigen/Dense>
#include <Eigen/Geometry>

class RelativeGoalPublisher
{
    public:
        RelativeGoalPublisher();
        void process(void);
        void odom_complement_callback(const nav_msgs::OdometryConstPtr&);
        void local_goal_callback(const geometry_msgs::PoseStampedPtr&);
        void goal_recreator(const nav_msgs::Odometry, const geometry_msgs::PoseStamped);

    private:

        bool odom_update_flag;
        bool local_goal_update_flag;

        ros::NodeHandle private_nh;

        nav_msgs::Odometry odom_complement;
        geometry_msgs::PoseStamped local_goal;
        geometry_msgs::PoseStamped relative_goal;

        //subscriber
        ros::Subscriber sub_odom_comp;
        ros::Subscriber sub_local_goal;
        //publisher
        ros::Publisher pub_relative_goal;

};
#endif