#ifndef __RELATIVE_GOAL_PUBLISHER_H
#define __RELATIVE_GOAL_PUBLISHER_H

#include <random>
#include <ros/ros.h>

#include <tf2_eigen/tf2_eigen.h>
#include <tf2/utils.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <tf/transform_listener.h>
#include <tf/transform_broadcaster.h>

// Eigen
#include <Eigen/Dense>
#include <Eigen/Geometry>

class RELATIVE_GOAL_PUBLISHER 
{
    public:
        void process(void);
    private:

};
#endif