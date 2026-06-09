### 解题思路
纯C 

### 代码

```c
typedef struct {
    int min;
    int top;
    int* data;
} MinStack;

/** initialize your data structure here. */
#define MAX_SIZE 5000

MinStack* minStackCreate() {
    MinStack* pStack = (MinStack*)malloc(sizeof(MinStack));
    pStack->min = INT_MAX;
    pStack->top = -1;
    pStack->data = (int*)malloc(MAX_SIZE * sizeof(int));
    return pStack;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->top == MAX_SIZE - 1)
    {
        return ;
    }

    obj->top++;
    obj->data[obj->top] = x;
    obj->min = x < obj->min ? x : obj->min;
}

void minStackPop(MinStack* obj) {
    if (-1 == obj->top)
    {
        return ;
    }

    int tmp = obj->data[obj->top];
    obj->top--;

    if (tmp == obj->min)
    {
        obj->min = INT_MAX;

        for (int i = obj->top; i > -1; i--)
        {
            obj->min = obj->data[i] < obj->min ? obj->data[i] : obj->min;
        }
    }
}

int minStackTop(MinStack* obj) {
    if (-1 == obj->top)
    {
        return 0;
    }

    return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj) {
    if (-1 == obj->top)
    {
        return 0;
    }

    return obj->min;
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