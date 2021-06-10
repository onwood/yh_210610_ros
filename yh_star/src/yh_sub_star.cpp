#include "ros/ros.h"
#include "yh_star/yh_msg_star.h"
#include <stdio.h>

using namespace std;

void msgCallback(const yh_star::yh_msg_star::ConstPtr &msg) //const: 상수
{
	ROS_INFO("receive msg = %d", msg -> data);
	for(int i=0; i < (msg -> data); i++)
	{
		for(int j=0; j < (msg -> data); j++)
		{
			if (j == 0)
			{
				printf("*");
			}
			else if (i+j >= (msg -> data))
			{
				printf(" ");
			}
			else if (i >= j) 
			{
				printf("*");
			}
			
		}	
		printf("\n");
	}
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "yh_sub_star");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("yh_topic_star", 100, msgCallback);
	ros::spin(); // 어떤 값이 들어오기 전까지 대기

	return 0;
}
