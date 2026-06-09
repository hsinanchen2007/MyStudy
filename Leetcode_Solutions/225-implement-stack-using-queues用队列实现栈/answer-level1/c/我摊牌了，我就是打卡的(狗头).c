### 解题思路
此处撰写解题思路

### 代码

```c
#define SIZE  1000
typedef struct {
    int ar[SIZE+1];
    int front;
    int rear;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->front = SIZE;
    stack->rear = SIZE;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->ar[(obj->front)--] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {

    return obj->ar[++(obj->front)];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    int top = obj->front+1;
    return obj->ar[top];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return (obj->front == obj->rear); 
}

void myStackFree(MyStack* obj) {
    free(obj->ar);
}
```