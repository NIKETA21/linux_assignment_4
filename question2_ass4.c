#include<stdio.h>
//#include<mutexaphore.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>

struct my_thread
{
	int thread_id;
	char msg[100];
};
void *printhello(void *threadobj)
{
	pthread_t thread_ID;
	struct my_thread *t1;
	t1=(struct my_thread *)threadobj;
	thread_ID = pthread_self();
	printf("\n thread ID : %u", thread_ID);
	printf("\n %d thread message : %s \n", t1->thread_id , t1->msg);
	}
int main()
{
	pthread_t thread2 , thread3 , thread4, thread_ID;
	int rc;
	struct my_thread t2,t3,t4;
	t4.thread_id = 4;
	strcpy(t4.msg , "i am fourth thread \n");
	t2.thread_id = 2;
	strcpy(t2.msg , "i am second thread \n");
	t3.thread_id = 3;
	strcpy(t3.msg , "i am third thread \n");
	thread_ID = pthread_self();
	printf("\n MAIN THREAD ID :%u", thread_ID);
	pthread_create(&thread4 , 0 ,printhello, (void *)&t4);
	pthread_create(&thread2 , NULL,printhello, (void *)&t2);
	pthread_create(&thread3, NULL,printhello, (void *)&t3);
	printf("\n exit from main thread \n");
	pthread_exit(NULL);
	}
