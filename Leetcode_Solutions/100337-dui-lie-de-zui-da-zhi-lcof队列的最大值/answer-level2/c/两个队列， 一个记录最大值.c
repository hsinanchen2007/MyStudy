```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10000
struct MyQueue {
    int item[MAX];
    int front;
    int rear;
};

bool IsEmpty(struct MyQueue *q)
{
    return q->front == -1;
}

struct MyQueue *CreateQueue(void)
{
    struct MyQueue *q = malloc(sizeof(*q));
    q->front = -1;
    q->rear = -1;
    return q;
}

void EnQueue(struct MyQueue *q, int val)
{
    q->item[++q->rear] = val;
    if (q->front == -1) {
        q->front = 0;
    }
}

int DeQueue(struct MyQueue *q)
{
    int val = q->item[q->front++];
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return val;
}

int GetFront(struct MyQueue *q)
{
    return q->item[q->front];
}

int GetRear(struct MyQueue *q)
{
    return q->item[q->rear];
}

void PopRear(struct MyQueue *q)
{
    q->rear--;
    if (q->rear < q->front) {
        q->rear = -1;
        q->front = -1;
    }
}

typedef struct {
    struct MyQueue *data;
    struct MyQueue *max;
} MaxQueue;


MaxQueue* maxQueueCreate() {
    MaxQueue *q = malloc(sizeof(*q));
    q->data = CreateQueue();
    q->max = CreateQueue();
    return q;
}

int maxQueueMax_value(MaxQueue* obj) {
    if (IsEmpty(obj->data)) {
        return -1;
    }

    return GetFront(obj->max);
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    while (!IsEmpty(obj->max)) {
        if (GetRear(obj->max) < value) {
            PopRear(obj->max);
        } else {
            break;
        }
    }

    EnQueue(obj->max, value);
    EnQueue(obj->data, value);
}

int maxQueuePop_front(MaxQueue* obj) {
    if (IsEmpty(obj->data)) {
        return -1;
    }

    int val = DeQueue(obj->data);
    if (val == GetFront(obj->max)) {
        DeQueue(obj->max);
    }
    
    return val;
}

void maxQueueFree(MaxQueue* obj) {
    free(obj->data);
    free(obj->max);
    free(obj);
}

/**
 * Your MaxQueue struct will be instantiated and called as such:
 * MaxQueue* obj = maxQueueCreate();
 * int param_1 = maxQueueMax_value(obj);

 * maxQueuePush_back(obj, value);

 * int param_3 = maxQueuePop_front(obj);

 * maxQueueFree(obj);
*/

```
