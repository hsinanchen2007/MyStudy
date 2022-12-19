### 解题思路
此处撰写解题思路

### 代码

```c
#define Max_Size 1000

typedef struct {
    int stack[Max_Size];
    int top;
    int tail;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj -> top = 0;
    obj -> tail = 0;
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->stack[obj->tail++] = x; 
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    obj->tail -= 1;
    return obj->stack[obj->tail];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {


    return obj->stack[obj->tail - 1]; 
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->top == obj->tail) return true;
    return false;
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