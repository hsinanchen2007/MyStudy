### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    int list[10000];
    int top;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* node = (MyStack*)malloc(sizeof(MyStack));
    node->top = -1;
    return node;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->top = obj->top + 1;
    obj->list[obj->top] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    return obj->list[(obj->top)--];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->list[obj->top];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (obj->top == -1) {
        return true;
    } else {
        return false;
    }
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