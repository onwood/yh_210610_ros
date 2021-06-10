#include "ros/ros.h"
#include "yh_sum/yh_msg_sum.h"
#include <stdio.h>
#include <vector>

using namespace std;
vector<int> v;

void msgCallback(const yh_sum::yh_msg_sum::ConstPtr &msg) //const: 상수
{
	int new_data = msg -> data;
	ROS_INFO("receive msg = %d", new_data);
	v.push_back(new_data);
	int added = v[v.size()-2] + new_data;
	ROS_INFO("receive old_msg = %d", v[v.size()-2]);
	ROS_INFO("receive added_msg = %d", added);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "yh_sub_sum");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("yh_topic_sum", 100, msgCallback);
	ros::spin(); // 어떤 값이 들어오기 전까지 대기

	return 0;
}
