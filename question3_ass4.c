#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

int sharedVar=5;
pthread_mutex_t my_mutex;
//pthread _
void *thread_inc (void *arg)
{

	pthread_t;
	mutex_wait(&my_mutex);
	sharedVar++;
	mutex_post(&my_mutex);
}

void *thread_dec(void *arg)
{

	mutex_wait(&my_mutex);
	sharedVar--;
	mutex_post(&my_mutex);
}

int main()
{
	pthread_t thread1, thread2;
	
	mutex_init(&my_mutex, 0,1);
	
	pthread_create(&thread1,NULL, thread_inc,NULL);
	
	pthread_create(&thread2,NULL, thread_dec,NULL);
	
	pthread_join(thread1,NULL);
	
	pthread_join(thread2,NULL);
	
	printf("sharedVar = %d\n",sharedVar);
	return 0;
}
