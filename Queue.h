#ifndef	__QUEUE_H__
#define	__QUEUE_H__
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct queue {
	int data[MAX_QUEUE_SIZE];
	int front,rear,length;
}queue,*Queue_Ptr;

Queue_Ptr InitQueue(Queue_Ptr p);
Queue_Ptr EnQueue(Queue_Ptr p,int e);
int DeQueue(Queue_Ptr p,int e);
int EmptyQueue(Queue_Ptr p);



#endif
