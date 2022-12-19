```

#define MAXSIZE 20
#define SIZEINCREMENT 10

typedef struct 
{
    int *top;
    int *base;
    int stacklen;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() 
{
    MinStack *obj = malloc(sizeof(MinStack));
    
    obj->base = (int *)malloc(sizeof(int) * MAXSIZE);
    if( !obj->base )
        return NULL;
    obj->top = obj->base;
    obj->stacklen = MAXSIZE;
    return obj;
}

void minStackPush(MinStack* obj, int x) 
{
    if( obj->top - obj->base >= obj->stacklen )
    {
        obj->base = (int *)realloc(obj->base,(obj->stacklen + SIZEINCREMENT ) * sizeof(int));
        if( ! obj->base )
            return NULL;
        obj->top = obj->base + obj->stacklen;
        obj->stacklen = obj->stacklen + SIZEINCREMENT;
    }
    *obj->top++ = x;
}

int minStackPop(MinStack* obj) 
{
    if( obj->top == obj->base )
        return NULL;
    return *--obj->top;
}

int minStackTop(MinStack* obj) 
{
    int e;
    if( obj->top == obj->base )
        return NULL;
    e = *--obj->top;
    obj->top++;
    return e;
}

void minStackBack(MinStack* obj)
{
    ++obj->top;             // 比较完后将top指针指回原位
}

int minStackGetMin(MinStack* obj) 
{
    int min = 2147483647;
    int i = 0;
    int temp;
    while( obj->top != obj->base )
    {
        temp = minStackPop(obj);
        if( temp < min )
            min = temp;
        i++;            // 计算比较次数
    }
    for( i; i>0 ; i-- )
        minStackBack(obj);          // 因为通过指针的移动 不改变数据所以将指针指回原来位置就可以
    return min;
}

void minStackFree(MinStack* obj) 
{
    free(obj);
}
```
