为什么数据量这么大

```c
typedef struct {
    int *data;
    int *min;
    int top;
    int mintop;

} MinStack;

/** initialize your data structure here. */

int  ifempty(MinStack *obj)
{
    if(obj->top == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
MinStack* minStackCreate() 
{
    MinStack *obj = (MinStack*)calloc(100000,sizeof(MinStack));
    obj->data = (int*)calloc(50000,sizeof(int));
    obj->min = (int*)calloc(50000,sizeof(int));
    obj->top = 0;
    obj->mintop = 0;
    return obj;
}

void minStackPush(MinStack* obj, int x)
{
    if(ifempty(obj))
    {
        obj->data[obj->top] = x;
        obj->min[obj->top] = x;
    }
    else
    {
    obj->data[obj->top] = x;
    int min = obj->min[obj->top-1 ];
    if(min > x)
    {
        obj->min[obj->top] = x;
    }
    else
    {
        obj->min[obj->top] = min;
    }
    }
    obj->top++;
}

void minStackPop(MinStack* obj) 
{
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->data[obj->top-1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->top-1];
}

void minStackFree(MinStack* obj) {
    obj->data = (int*)calloc(100,sizeof(int));
    obj->min = (int*)calloc(100,sizeof(int));
    obj->top = 0;
    obj->mintop = 0;
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