### 解题思路
跟用栈实现队列差不多，就是pop的时候，应该pop的是刚刚push进队列的元素，为了实现这一点，可以在push之前，利用另一个队列，将当前队列清空，然后push元素，再将另一个队列的元素push回来。

### 代码

```c
#define MAX_LEN 100
typedef struct {
    int front;
    int tail;
    int data[MAX_LEN];
} queue;

typedef struct {
    int top;
    queue q1;
    queue q2;
} MyStack;

/** Initialize your data structure here. */


MyStack* myStackCreate() {
    MyStack *stack = (MyStack*)malloc(sizeof(MyStack) * MAX_LEN);
    memset(stack, 0, sizeof(MyStack) * MAX_LEN);

    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->q1.data[obj->q1.tail] = x;
    (obj->q1.tail)++;

    return 0;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    for (int i = 0; i < obj->q1.tail - 1; i++) {
        obj->q2.data[i] = obj->q1.data[i];
        (obj->q2.tail)++;
    }

    int temp = obj->q1.data[obj->q1.tail - 1];
    obj->q1.tail = 0;

    for (int i = 0; i < obj->q2.tail; i++) {
        obj->q1.data[i] = obj->q2.data[i];
        (obj->q1.tail)++;
    }
    obj->q2.tail = 0;
    return temp;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    int temp;
    temp = obj->q1.data[obj->q1.tail - 1];

    return temp;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    int front = obj->q1.front;
    int tail = obj->q1.tail;

    return front == tail;
}

void myStackFree(MyStack* obj) {
    memset(obj, 0, sizeof(MyStack));
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