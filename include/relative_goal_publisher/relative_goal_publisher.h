#ifndef __RELATIVE_GOAL_PUBLISHER_H
#define __RELATIVE_GOAL_PUBLISHER_H

#include <random>
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>

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

    private:

        bool odom_update_flag;

        ros::NodeHandle private_nh;

        nav_msgs::Odometry current_odom;

        //subscriber
        ros::Subscriber sub_odom_comp;
        //publisher
};
#endif