### 解题思路
C语言随便写了下，好像不太符合题目的要求

### 代码

```c
typedef struct {
    int* val;
    int top;
    int bot;
    int num;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* newstack = (MyStack*)malloc(sizeof(MyStack));
    newstack->val = (int*)malloc(sizeof(int) * 1000);
    newstack->top = -1;
    newstack->bot = -1;
    newstack->num = 0;

    return newstack;   
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->val[++obj->top] = x;
    obj->bot = 0;
    obj->num++;

    return;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int ret;

    ret = obj->val[obj->top];
    obj->top--;
    obj->num--;
    if (obj->top == -1) {
        obj->bot = -1;
    }

    return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->val[obj->top];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (obj->num == 0) {
        return true;
    }

    return false;
}

void myStackFree(MyStack* obj) {

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