### 解题思路
该方法不是最优解法，后期仍旧需要优化。

### 代码

```c
#define STACKLEN 20

typedef struct {
    int* data;
    int head, rear;
    int size;
    int amount;
} Queue;

typedef struct {
    Queue* q1;
} MyStack;

Queue* initQueue(int n){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q -> data = (int*)malloc(n * sizeof(int));
    q -> head = -1;
    q -> rear = -1;
    q -> size = n;
    q -> amount = 0;
    return q;
}

void enQueue(Queue *q, int a){
    if(q -> head == -1) q -> head = 0;
    q -> rear = (q -> rear + 1) % q -> size;
    q -> data[q -> rear] = a;
    q -> amount ++;
}

int deQueue(Queue* q){
    int out = q -> data[q -> head];
    if(q -> head == q -> rear){
        q -> head = -1;
        q -> rear = -1;
        q -> amount --;
        return out;
    }
    q -> head = (q -> head + 1) % q ->size;
    q -> amount --;
    return out;
}

int isEmpty(Queue* q){
    return q -> head == -1;
}


/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* s = (MyStack*)malloc(sizeof(MyStack));
    s -> q1 = initQueue(STACKLEN);
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    enQueue(obj -> q1, x); 
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int n = obj -> q1 -> amount;
    int tmp;
    for(int i = 1; i < n; i++){
        tmp = deQueue(obj -> q1);
        enQueue(obj -> q1, tmp);
    }
    tmp = deQueue(obj -> q1);
    return tmp;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj -> q1 -> data[obj -> q1 -> rear];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj -> q1 -> head == -1){
        return true;
    }
    return false;
}

void myStackFree(MyStack* obj) {
    free(obj -> q1 -> data);
    obj -> q1 -> data = NULL;
    free(obj -> q1);
    obj -> q1 = NULL;
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