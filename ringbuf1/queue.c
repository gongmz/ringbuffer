#include "ringbuffer/queue.h"

#define QUEUE_SIZE 400               //队列最大空间
#define ARRAY_SIZE (QUEUE_SIZE+1)   //留出1个余量，用来判断满或空
#define QUEUE_TYPE char

SqQueue Queue;

static QUEUE_TYPE queue[ARRAY_SIZE];
/*
**初始化
*/
void InitQueue( SqQueue *Q )
{
        Q->base = queue;
        Q->front = 1;
        Q->rear = 0;
}
/*
**清队列缓冲区
*/
void clearQueue( SqQueue *Q )
{
    memset(queue,0,sizeof(queue));//清空缓冲区
    Q->front = 1;
    Q->rear = 0;
}
/*
**获取队列长度
*/
uint8_t QueueLength( const SqQueue *Q )
{
        return (Q->rear - Q->front + ARRAY_SIZE + 1)%ARRAY_SIZE;
}
/*
**判断队列是否为空
*/
bool QueueIsEmpty( const SqQueue *Q )
{
        return (Q->rear + 1)%ARRAY_SIZE==Q->front;
}
/*
**判断队列是否满
*/
bool QueueIsFull( const SqQueue *Q )
{
        return (Q->rear + 2)%ARRAY_SIZE==Q->front;
}
/*
**插入队列
*/
uint8_t EnQueue( SqQueue *Q , char e )
{
     if( (Q->rear + 2) % ARRAY_SIZE == Q->front )//判断当前队列是否已满
         return 0;
     Q->rear = (Q->rear + 1)%ARRAY_SIZE;//
     Q->base[Q->rear] = e;
     return 1;
}
/*
**从队头取出数据
*/
uint8_t DeQueue( SqQueue *Q ,  char *e )
{
   if( (Q->rear + 1) % ARRAY_SIZE == Q->front )//判断当前队列是否为空
         return 0;
   *e = Q->base[Q->front];
   Q->front = (Q->front + 1)%ARRAY_SIZE;
   return 1;
}
