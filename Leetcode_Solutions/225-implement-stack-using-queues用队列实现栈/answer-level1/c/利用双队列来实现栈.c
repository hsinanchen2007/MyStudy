### 解题思路
利用双队列来实现栈的 POP（把原数据队列重新入另一空队列，原数据队列尾不入新队列，原数据队列尾的值就是栈顶） 和 TOP （把原数据队列重新入另一空队列，原数据队列尾也一起入新队列，原数据队列尾的值就是栈顶）操作，PUSH只需要放到数据队列尾就行了
### 代码

```c
#define MAX_QUEUE_SIZE 1000

typedef struct {
    int queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int queueSize;
} Queue;

typedef struct {
    Queue queue1;
    Queue queue2;
    int stackSize;
} MyStack;

bool myStackEmpty(MyStack* obj);

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *myStack = NULL;

    myStack = (MyStack *)malloc(sizeof(MyStack));
    if (myStack == NULL) {
        return NULL;
    }

    myStack->stackSize = 0;
    myStack->queue1.queueSize = 0;
    myStack->queue1.front = 0;
    myStack->queue1.rear = MAX_QUEUE_SIZE - 1;
    myStack->queue2.queueSize = 0;
    myStack->queue2.front = 0;
    myStack->queue2.rear = MAX_QUEUE_SIZE - 1;

    return myStack;
}

void EnQueue(Queue *q, int x)
{
    int rear;

    rear = q->rear;
    rear = rear + 1;
    if (rear == MAX_QUEUE_SIZE) {
        rear = 0;
    }

    q->queue[rear] = x;
    q->rear = rear;
    q->queueSize += 1;
}

void DelQueue(Queue *q)
{
    if (q->queueSize) {
        q->queueSize -= 1;
        q->front += 1;
        if (q->front == MAX_QUEUE_SIZE) {
            q->front = 0;
        }
    }
}

int QueuePop(Queue *q) 
{
    int pop = -1;

    if (q->queueSize) {
        q->queueSize -= 1;
        pop = q->queue[q->front];
        q->front += 1;
        if (q->front == MAX_QUEUE_SIZE) {
            q->front = 0;
        }
    }

    return pop;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (obj->queue1.queueSize) {
        EnQueue(&obj->queue1, x);
    } else {
        EnQueue(&obj->queue2, x);
    }

    obj->stackSize += 1;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) 
{
    int top;

    if (myStackEmpty(obj)) {
        return -1;
    }                                                                                              

    while (obj->queue1.queueSize > 1) {
        top = QueuePop(&obj->queue1);
        EnQueue(&obj->queue2, top);
    }
    if (obj->queue1.queueSize == 1) {
        top = QueuePop(&obj->queue1);
        obj->stackSize -= 1;
        return top;
    }
    while (obj->queue2.queueSize > 1) {
        top = QueuePop(&obj->queue2);
        EnQueue(&obj->queue1, top);
        printf("\ntop = %d \n", top);
    }
    top = QueuePop(&obj->queue2);
    obj->stackSize -= 1;
    return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    int top;

    if (myStackEmpty(obj)) {
        return -1;
    }    
                                                                                     
    if (obj->queue1.queueSize) {
        while (obj->queue1.queueSize > 0) {
            top = QueuePop(&obj->queue1);
            EnQueue(&obj->queue2, top);
        }
        return top;
    }
 
    while (obj->queue2.queueSize > 0) {
        top = QueuePop(&obj->queue2);
        EnQueue(&obj->queue1, top);
    }

    return top;    
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) 
{
    if (obj->stackSize == 0) {
        return true;
    }

    return false;
}

void myStackFree(MyStack* obj) {
    free(obj);
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