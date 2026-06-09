### 解题思路
用两个数组栈，同一个栈顶指针，一个栈用来保存数据，另一个栈用来指定当前的min值

### 代码

```c
#define MIN(a, b)  ((a<b) ? a : b)
#define MAXSTACK 10000

typedef struct {
    int *stackMemory;
    int *stackMinMemory;
    int top;
} MinStack;


/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *minStack = (MinStack *)malloc(sizeof(MinStack));
    
    minStack->stackMemory = (int *)malloc(sizeof(int) * MAXSTACK);
    minStack->stackMinMemory = (int *)malloc(sizeof(int) * MAXSTACK);
    minStack->top = -1;

    return minStack;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->top + 1 > MAXSTACK)
        return ;

    int min = x;

    if (obj->top != -1)
    {
        min = MIN(obj->stackMinMemory[obj->top], x);
    }

    int top = ++obj->top;
    
    obj->stackMinMemory[top] = min;
    obj->stackMemory[top] = x;
}

void minStackPop(MinStack* obj) {
    //obj->stackMemory[obj->top];
    //obj->stackMinMemory[obj->top];
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stackMemory[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->stackMinMemory[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
```