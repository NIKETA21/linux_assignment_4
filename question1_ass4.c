#include<stdio.h>
#include<stdlib.h>
#include<sys/mman.h>

#include<pthread.h>
#include<unistd.h>
void *my(void *i)
{

	printf("\n i am in %d thread \n", (int *)i);
	
}
main()
{
	pthread_t tid;
	struct sched_param param;
	int priority, policy, ret;
	ret = pthread_getschedparam (pthread_self(), &policy, &param);
	printf("\n_______ main thread _________\n policy :%d\t priority : %d \n", policy, param.sched_priority);
	policy = SCHED_FIFO;
	param.sched_priority = 3;
	pthread_setschedparam( pthread_self(), policy, & param);
	pthread_getschedparam(pthread_self(), &policy, &param);
	printf("______________main thred __________\n policy :%d \t priority :%d\n", policy, param.sched_priority);
	
}
