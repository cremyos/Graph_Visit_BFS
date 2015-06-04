/*
 ************************************************
 *Name : queue.c                                *
 *Date : 2015-06-04                             *
 *Author : sniper                               *
 *Aim : Queue basic operation.                  *
 ************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

/*
 *Init the queue
 */
Queue_Ptr InitQueue(Queue_Ptr p)
{
	p=(Queue_Ptr)malloc(sizeof(queue));
	memset(p->data,0,sizeof(p->data));
	p->front = p->rear=0;
	p->length=0;

	return p;
}

/*
 *Enter the queue
 */
Queue_Ptr EnQueue(Queue_Ptr p,int e)
{
	p->data[p->rear]=e;
	p->rear=(p->rear+1)%MAX_QUEUE_SIZE;
	p->length++;
	
	return p;
}

/*
 *Delete the queue
 */
int DeQueue(Queue_Ptr p,int e)
{
	e=p->data[p->front];
	p->front=(p->front+1)%MAX_QUEUE_SIZE;
	p->length--;

	return e;
}

/*
 *Judge the queue null or not
 */
int EmptyQueue(Queue_Ptr p)
{
	if(p->front==p->rear)
		return 0;
	else 
		return 1;
}



