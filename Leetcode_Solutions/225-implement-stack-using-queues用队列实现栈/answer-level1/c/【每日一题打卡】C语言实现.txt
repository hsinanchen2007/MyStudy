### 解题思路
我采用了两个结构，一个是队列，一个是栈，在栈中储存队列的位置并记录队尾，这样逻辑会稍微简单一些，细节部分代码中都有注释

### 代码

```c
typedef struct Queue {
    int val;
    struct Queue* next;
} *Queue;

typedef struct {
    Queue Q;
    Queue rear;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* S;
    S = (MyStack *)malloc(sizeof(MyStack));
    S->Q = (Queue)malloc(sizeof(struct Queue));
    S->Q->next = NULL;
    S->rear = S->Q;

    return S;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    Queue newNode;
    newNode = (Queue *)malloc(sizeof(struct Queue));
    newNode->val = x;
    newNode->next = NULL;

    // 入队操作，新元素必须在队尾
    obj->rear->next = newNode;
    obj->rear = newNode;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    // 栈顶元素实际上是队尾元素，前面的元素先需要出队
    int popVal;
    // 这里新建一个队列存储出队的元素
    Queue orgQ, tmpQ, rear;
    tmpQ = (Queue)malloc(sizeof(struct Queue));
    tmpQ->next = NULL;
    rear = tmpQ;

    orgQ = obj->Q;

    while(orgQ->next->next != NULL) {
        rear->next = orgQ->next;
        orgQ = orgQ->next;
        rear = rear->next;
    }

    // 把栈中的队列替换为新建的队列，省去了再一次出队入队的操作
    // 这里的顺序很重要
    obj->Q = tmpQ;
    popVal = orgQ->next->val;
    free(orgQ->next);
    rear->next = NULL;
    obj->rear = rear;
    return popVal;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    // 因为栈的结构中存储了队尾，直接返回队尾元素的值就可以
    return obj->rear->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (obj->rear == obj->Q)
        return true;
    return false;
}

void myStackFree(MyStack* obj) {
    Queue tmp;
    tmp = obj->Q;
    while (tmp) {
        obj->Q = obj->Q->next;
        free(tmp);
        tmp = obj->Q;
    }
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