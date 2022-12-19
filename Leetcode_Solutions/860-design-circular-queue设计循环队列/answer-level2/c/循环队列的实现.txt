### 解题思路
预留队列中的一位用于区分空队列和满队列，-1操作可以通过加模值避免负数无法求余。
### 代码

```c
typedef struct {
    int *data;
    int *head;
    int *tail;
    int size;
    
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *q = NULL;
    q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    memset(q, 0, sizeof(MyCircularQueue));
    q->data = (int *)malloc(sizeof(int)*(k + 1));
    memset(q->data, 0, (sizeof(int)*(k + 1)));
    q->head = q->data;
    q->tail = q->data;
    *(q->data) = -1;
    q->size = k;
    return q;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))
        return false;
    if(myCircularQueueIsEmpty(obj))
        obj->tail = obj->head = obj->data + 1;
    else
        obj->tail++;
    if(obj->tail >= obj->data + obj->size + 1)
        obj->tail = obj->data + 1;
    *obj->tail = value;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return false;
    *obj->head = 0;
    if(obj->head == obj->tail)
    {
        obj->head = obj->data;
        obj->tail = obj->data;
        return true;
    }    
    obj->head++;
    if(obj->head >= obj->data + obj->size + 1)
        obj->head = obj->data + 1;
    return true;   
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    return *(obj->head);
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    return *(obj->tail);
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->head == obj->data && obj->tail == obj->data)
        return true;
    else
        return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if((obj->head - obj->tail == 1)||(obj->tail - obj->head >= obj->size - 1))
        return true;
    else
        return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}
```