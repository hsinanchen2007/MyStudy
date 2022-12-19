### 解题思路
此处撰写解题思路

### 代码

```c
#define  MAX_DATA_NUM  1024
typedef struct {
    int front;
    int tail;
    int size;
    int *data;
} MyQueue;

typedef struct {
    MyQueue *q1;
    MyQueue *q2;
} MyStack;

MyQueue* myQueueCreate()
{
    MyQueue* queue = NULL;
    queue = (MyQueue*)malloc(sizeof(MyQueue));
    if (queue == NULL) {
        return NULL;
    }
    queue->data = (int *)malloc(sizeof(int) * MAX_DATA_NUM);
    if (queue->data == NULL) {
        free(queue);
        return NULL;
    }
    memset(queue->data, 0, MAX_DATA_NUM);
    queue->front = 0;
    queue->tail = 0;
    queue->size = 0;

    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj->tail == MAX_DATA_NUM) {
        return;
    }

    obj->data[obj->tail] = x;
    obj->tail++;
    obj->size++;

    return;
}

/** Removes the element on top of the stack and returns that element. */
int myQueuePop(MyQueue* obj) {
    int returnValue;
    if (obj->tail == 0) {
        return 0;
    }
    returnValue = obj->data[obj->front];

    obj->front++;
    obj->size--;

    return returnValue;
}
void changeTwoQueue(MyQueue* q1, MyQueue* q2)
{
    int i;
    for (i = 0; i < MAX_DATA_NUM; i++) {
        q1->data[i] = q2->data[i];
    }

    q1->tail = q2->tail;
    q1->front = q2->front;
    q1->size = q2->size;

    memset(q2->data, 0, MAX_DATA_NUM);
    q2->size = 0;
    q2->front = 0;
    q2->tail = 0;

    return;
}
/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* stack = NULL;
    stack = (MyStack*)malloc(sizeof(MyStack));
    if (stack == NULL) {
        return NULL;
    }
    stack->q1 = myQueueCreate();
    stack->q2 = myQueueCreate();
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    myQueuePush(obj->q1, x);
    return;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int tmp = 0;
    while (obj->q1->size > 1) {
        tmp = myQueuePop(obj->q1);
        myQueuePush(obj->q2, tmp);
    }
    tmp = myQueuePop(obj->q1);
    changeTwoQueue(obj->q1, obj->q2);

    return tmp;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    //printf("tail = %d /n", obj->q1->tail);
    int tmp;
    
    return obj->q1->data[obj->q1->tail-1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (obj->q1->size > 0) {
        return false;
    } else {
        return true;
    }
}

void myStackFree(MyStack* obj) {
    free(obj->q1->data);
    obj->q1->data = NULL;
    free(obj->q1);
    obj->q1 = NULL    ;
    free(obj->q2->data);
    obj->q2->data = NULL;
    free(obj->q2);
    obj->q2 = NULL;
    free(obj);
    obj = NULL;
    return;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
```