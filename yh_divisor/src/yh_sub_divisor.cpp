#include "ros/ros.h"
#include "yh_divisor/yh_msg_divisor.h"
#include <stdio.h>
#include <vector>

using namespace std;


void msgCallback(const yh_divisor::yh_msg_divisor::ConstPtr &msg) //const: 상수
{
	ROS_INFO("receive msg = %d", msg -> data);
	for(int i=1; i <= (msg -> data); i++)
	{
		if ((msg -> data) % i == 0)
		{
			cout << i << " ";
			
		}
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "yh_sub_divisor");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("yh_topic_divisor", 100, msgCallback);
	ros::spin(); // 어떤 값이 들어오기 전까지 대기

	return 0;
}
