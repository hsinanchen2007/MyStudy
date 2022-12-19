### 解题思路
此处撰写解题思路
两个队列，时刻保持1个是空的，只有1个队列中有数据
1、push操作：数据进入非空队列人尾部
2、pop操作: 非空队列人数据全部出队，除最后1个元素外，全部数据进入另一个队列。

### 代码

```c

#define MAX 100000

typedef struct {
    int item[MAX];
    int rear;
    int front;
}MyQueue;

MyQueue* myQueueCreate() {
    MyQueue *q = malloc(sizeof(MyQueue));
    q->rear = -1;
    q->front = -1;
    return q;
}

bool isEmptyQueue(MyQueue *q)
{
    return q->front == -1;
}

void enQueue(MyQueue* q, int elem)
{
    q->item[++q->rear] = elem;
    if (q->front == -1) {
        q->front = 0;
    }
}

int deQueue(MyQueue* q)
{
    int val = q->item[q->front++];
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    return val;
}

typedef struct {
    MyQueue *q1;
    MyQueue *q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* stk = malloc(sizeof(MyStack));
    stk->q1 = myQueueCreate();
    stk->q2 = myQueueCreate();
    return stk;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (!isEmptyQueue(obj->q1)) {
        enQueue(obj->q1, x);
    } else {
        enQueue(obj->q2, x);      
    } 
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int i;
    int tmp;
    if (!isEmptyQueue(obj->q1)) {
        while (obj->q1->front < obj->q1->rear) {
            tmp = deQueue(obj->q1);
            enQueue(obj->q2, tmp);
        }
        tmp = deQueue(obj->q1);
    } else {
        while (obj->q2->front < obj->q2->rear) {
            tmp = deQueue(obj->q2);
            enQueue(obj->q1, tmp);
        }
        tmp = deQueue(obj->q2);        
    }
    
    return tmp;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (!isEmptyQueue(obj->q1)) {
        return obj->q1->item[obj->q1->rear];
    } else {
        return obj->q2->item[obj->q2->rear];      
    }  
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return isEmptyQueue(obj->q1) && isEmptyQueue(obj->q2);  
}

void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
    obj = NULL;
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