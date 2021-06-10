#include "ros/ros.h"
#include "yh_210608_4/yh_msg_4.h"

void msgCallback(const yh_210608_4::yh_msg_4::ConstPtr &msg) //const: 상수
{
	ROS_INFO("receive msg_sec = %d", msg -> stamp.sec);
	ROS_INFO("receive msg_nec = %d", msg -> stamp.nsec);
	ROS_INFO("receive msg_data = %d", msg -> data);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "yh_sub_4");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("yh_topic_test", 100, msgCallback);
	ros::spin(); // 어떤 값이 들어오기 전까지 대기

	return 0;
}
