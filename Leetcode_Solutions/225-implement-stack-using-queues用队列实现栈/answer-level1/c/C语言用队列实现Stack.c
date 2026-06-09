### 解题思路
PUSH：正常入队
POP：建立一个临时队列

### 代码

```c
#define MAX_SIZE 10000
// #define INT_MAX 100000

typedef struct {
    int front;
    int rear;
    int size;
    int arrQueue[MAX_SIZE];
} Queue;

void initQueue(Queue *queue) {
    if (queue == NULL) {
        return;
    }

    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    memset(queue->arrQueue, 0x0, sizeof(int) * MAX_SIZE);

    return;
}

void queuePush(Queue *queue, int value)
{
    if ((queue == NULL) || (queue->size > MAX_SIZE)) {
        return;
    }

    queue->front++;
    queue->arrQueue[queue->front] = value;
    queue->size++;

    return;
}

int queuePop(Queue *queue) {
    if ((queue == NULL) || (queue->size == 0)) {
        return INT_MAX;
    }

    queue->rear++;
    queue->size--;

    return queue->arrQueue[queue->rear];
}

int queueSize(Queue *queue)
{
    if (queue == NULL) {
        return 0;
    }

    return queue->size;
}

typedef struct {
    Queue *queue;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->queue = (Queue *)malloc(sizeof(Queue));
    initQueue(stack->queue);

    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (obj == NULL) {
        return;
    }

    queuePush(obj->queue, x);
    return;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if (obj == NULL) {
        return INT_MAX;
    }

    Queue *tmp = (Queue *)malloc(sizeof(Queue));
    int ans;
    int size = queueSize(obj->queue); // 注意每次调用pop时size都会发生改变，所以先记录

    initQueue(tmp);
    // printf("size : %d\n",queueSize(obj->queue));
    for (int i = 0; i < size - 1; i++) {
        int pop = queuePop(obj->queue);
        queuePush(tmp, pop);
        // printf("for : %d  %d\n ",pop, i );
    }

    ans = queuePop(obj->queue);
    printf("%d", ans);
    free(obj->queue);
    obj->queue = tmp;
    return ans;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (obj == NULL) {
        return INT_MAX;
    }

    int ans = myStackPop(obj);
    myStackPush(obj, ans);
    return ans;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (obj == NULL) {
        return true;
    }

    return queueSize(obj->queue) == 0 ? true : false;
}

void myStackFree(MyStack* obj) {
    if (obj == NULL) {
        return;
    }

    if (obj->queue != NULL) {
        free(obj->queue);
    }

    free(obj);
    return ;
}
```