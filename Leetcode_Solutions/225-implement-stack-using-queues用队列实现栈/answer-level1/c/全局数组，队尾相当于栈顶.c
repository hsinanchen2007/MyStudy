### 解题思路
定义了一个全局数组，然后队尾相当于栈顶，写完发现队头front用不到。

### 代码

```c
#define MAX_SIZE 1024
int array[MAX_SIZE];
//队尾相当于栈顶
typedef struct {
    //int front;
    int rear;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->rear = 0;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    array[(obj->rear)++] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    return array[--(obj->rear)];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return array[(obj->rear) - 1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->rear == 0;
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