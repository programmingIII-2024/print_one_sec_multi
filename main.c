#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread1(void *pParam);
void *thread2(void *pParam);

int count=0; 

int main(void)
{
	pthread_t thread_id1,thread_id2;

	pthread_create(&thread_id1, NULL, thread1, NULL);
	pthread_create(&thread_id2, NULL, thread2, NULL);

	//スレッド終了待ち
	pthread_join(thread_id1,NULL);
	pthread_join(thread_id2,NULL);

	return 0;
}

void *thread1(void *pParam)
{
	while(1)
	{
		printf("%d\n",count);
		sleep(1);
		count++;
	}
}

void *thread2(void *pParam)
{
	while(1)
	{
		scanf("%d",&count);
	}
}
