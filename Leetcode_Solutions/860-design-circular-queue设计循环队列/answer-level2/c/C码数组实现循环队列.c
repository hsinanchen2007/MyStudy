### 解题思路
使用数组实现循环队列需要注意以下几点：
1. 初始化时front和tail均设置为-1;
2. front和tail取值都和最大值进行求模运算；
3. 在只有一个节点数据的时候，front和tail要设置为相等。

### 代码

```c
typedef struct {
    int *data;
    int front;
    int tail;
    int max;
    int count;    
} MyCircularQueue;

MyCircularQueue myQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) 
{
    memset(&myQueue, 0, sizeof(myQueue));
    myQueue.data = (int *)malloc(sizeof(int) * k);
    if (myQueue.data == NULL) {
        return NULL;
    }

    memset(myQueue.data, 0, sizeof(int) * k);
    myQueue.max = k;
    myQueue.count = 0;
    myQueue.front = -1;
    myQueue.tail = -1;
    return &myQueue;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) 
{
    return (obj->count == 0) ? true : false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) 
{
    return (obj->count == obj->max) ? true : false;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) 
{
    if (myCircularQueueIsFull(obj)) {
        return false;
    }

    obj->tail = (obj->tail + 1) % obj->max;
    obj->data[obj->tail] = value;
    obj->count++;

    if (obj->count == 1) {
        obj->front = obj->tail;
    }

    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) 
{
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }

    obj->data[obj->front] = 0;
    obj->front = (obj->front) + 1 % obj->max;
    obj->count--;
    if (obj->count == 0) {
        obj->front = -1;
        obj->tail = -1;
    }
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) 
{
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->data[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) 
{   
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->data[obj->tail];
}

void myCircularQueueFree(MyCircularQueue* obj) 
{
    if (obj->data) {
        free(obj->data);
        obj->data = NULL;
    }    

    memset(obj, 0, sizeof(MyCircularQueue));

    return;
}
```

### 执行效果

执行用时 :44 ms, 在所有 C 提交中击败了38.75%的用户
内存消耗 :12.5 MB, 在所有 C 提交中击败了100.00%的用户