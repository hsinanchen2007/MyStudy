```
#define MAXSIZE 1024
typedef struct {
    int *data;
    int rear;
    int front;
} Queue;

bool isEmpty(Queue *q) {
    return q->rear == q->front;
}

bool isFull(Queue *q) {
    return (q->rear + 1) % MAXSIZE == q->front;
}

int sizeOfQueue(Queue *q) {
    return (q->rear + MAXSIZE - q->front) % MAXSIZE;
}

void enQueue(Queue *q, int x) {
    if (isFull(q)) {
        return;
    }
    q->data[q->rear++] = x;
    return;
}

void deQueue(Queue *q, int *x) {
    if (isEmpty(q)) {
        return;
    }
    *x = q->data[q->front++];
    return;
}

typedef struct {
    Queue q1, q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *obj = (MyStack*)malloc(sizeof(MyStack));
    obj->q1.data  = (int*)malloc(sizeof(int) * MAXSIZE);
    obj->q1.front = 0;
    obj->q1.rear  = 0;
    obj->q2.data  = (int*)malloc(sizeof(int) * MAXSIZE);    
    obj->q2.front = 0;
    obj->q2.rear  = 0;
    return obj;
}

/** Push element x onto stack. */
/* 哪个队列非空, 就往哪个入队 */
void myStackPush(MyStack* obj, int x) {
    if (!isEmpty(&obj->q1)) {
        enQueue(&obj->q1, x);
    } else {
        enQueue(&obj->q2, x);
    }
}

/** Removes the element on top of the stack and returns that element. */
/* 将一个队列元素转移到另一个中, 特殊处理最后一个元素, 即栈顶 */
int myStackPop(MyStack* obj) {
    int x = 0;
    if (!isEmpty(&obj->q1)) {
        while (sizeOfQueue(&obj->q1) > 1) {
            deQueue(&obj->q1, &x);
            enQueue(&obj->q2, x);
        }
        deQueue(&obj->q1, &x);
    } else {
        while (sizeOfQueue(&obj->q2) > 1) {
            deQueue(&obj->q2, &x);
            enQueue(&obj->q1, x);
        }
        deQueue(&obj->q2, &x);
    }
    return x;
}

/** Get the top element. */
/* 同上, 只是不用出栈 */
int myStackTop(MyStack* obj) {
    int x = 0;
    if (!isEmpty(&obj->q1)) {
        while (sizeOfQueue(&obj->q1) > 0) {
            deQueue(&obj->q1, &x);
            enQueue(&obj->q2, x);
        }
        return x;
    } else {
        while (sizeOfQueue(&obj->q2) > 0) {
            deQueue(&obj->q2, &x);
            enQueue(&obj->q1, x);
        }
    }
    return x;
}

/** Returns whether the stack is empty. */
/* 两队列都为空, 即是空栈 */
bool myStackEmpty(MyStack* obj) {
    if (isEmpty(&obj->q1) && isEmpty(&obj->q2)) {
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj->q1.data);
    free(obj->q2.data);
    free(obj);
}

```
