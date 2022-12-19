### 解题思路
gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!
gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!gogogogog!!!
### 代码

```c

typedef struct {
    int nums[100];
    int front, rear;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *stack = (MyStack*)malloc(sizeof(MyStack));
    stack->front = 0;
    stack->rear = -1;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->nums[++(obj->rear)] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int x = obj->nums[(obj->rear)--];
    return x;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->nums[obj->rear];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->rear == -1;
}

void myStackFree(MyStack* obj) {
    free(obj);
}
```