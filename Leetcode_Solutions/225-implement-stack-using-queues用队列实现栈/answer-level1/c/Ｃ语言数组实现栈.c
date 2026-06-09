### 解题思路
数组实现栈的进出操作
top指向下一个空位置
性能一般

### 代码

```c
#define MAXSIZE 10000
typedef struct {
    int vec[MAXSIZE];
    int top;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* ret = (MyStack*)calloc(1, sizeof(MyStack));
    ret->top = 0;
    return ret;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->vec[obj->top++] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if (obj->top != 0) return (obj->vec[--obj->top]);
    return INT_MIN;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if (obj->top != 0) return (obj->vec[obj->top - 1]);
    return INT_MIN;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return (obj->top == 0);
}

void myStackFree(MyStack* obj) {
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