### 解题思路
打卡加油

### 代码

```c
#define STACK_SIZE (200)

typedef struct {
    int *base;
    int *top;
    int stackSize;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    if (stack == NULL) {
        return  NULL;
    }

    stack->base = (int *)malloc(STACK_SIZE * sizeof(int));
    if (stack == NULL) {
        return  NULL;
    }
    stack->top = stack->base;
    stack->stackSize = STACK_SIZE;
    return stack;
}

int myStackIsFull(MyStack *obj)
{
    return obj->top - obj->base == STACK_SIZE - 1;
}


/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (myStackIsFull(obj)) {
        return;
    }

    *obj->top++ = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    //判断是否是空
    return *--obj->top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return *(obj->top - 1);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return (obj->top == obj->base ) ? true : false; 
}

void myStackFree(MyStack* obj) {
    free(obj->base);
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