#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char *base;  //初始化的动态分配存储空间
    uint16_t front;  //头指针，若队列不空，指向队列头元素
    uint16_t rear;   //尾指针，若队列不空，指向队列尾元素
}SqQueue;

extern SqQueue Queue;

void InitQueue( SqQueue *Q );
uint8_t QueueLength(const SqQueue *Q );
bool QueueIsEmpty( const SqQueue *Q );
bool QueueIsFull(const SqQueue *Q );
uint8_t EnQueue( SqQueue *Q , char e );
uint8_t DeQueue( SqQueue *Q ,  char *e );
void clearQueue( SqQueue *Q );
#endif
