### 解题思路
定义了一个数组和top作为当前的栈顶的位置， top 为0 即为空；栈顶元素为数组中 top - 1；
入栈 top++,出栈 top--


### 代码

```c
#define     MAX_DEPTH       100000
typedef struct {
    int     stack[MAX_DEPTH];
    int     top;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *stack;
    stack = (MyStack *)malloc(sizeof(MyStack));
    stack->top = 0;
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (obj->top < MAX_DEPTH) {
        obj->stack[obj->top++] = x;
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int     value = 0;
    if (obj->top > 0) {
        value =  obj->stack[--obj->top];
    }
    return value;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (obj->top > 0) {
        return obj->stack[obj->top - 1];
    }
    return 0;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    bool empty;
    empty = (obj->top == 0) ? true : false;
    return empty;
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