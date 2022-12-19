### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct {
    void **data;
    int top;
    int size;
} Stack;

Stack *StackCreate(int stackSize)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }

    stack->data = (void **)malloc(sizeof(void **) * (stackSize + 1));
    memset(stack->data, 0, sizeof(void **) * (stackSize + 1));
    stack->top = -1;
    stack->size = stackSize;
    return stack;
}

void StackFree(Stack *obj)
{
    if (obj->data != NULL) {
        free(obj->data);
        obj->data = NULL;
    }
    free(obj);
    obj = NULL;
    return;
}

bool IsStackEmpty(Stack *obj)
{
    return (obj->top == -1);
}

bool IsStackFull(Stack *obj)
{
    return (obj->top ==  obj->size);
}

void StackPush(Stack *obj, void *data)  // 泛型接口，使用void *
{
    if (IsStackFull(obj) == true) {
        return;
    }
    int top = obj->top;
    obj->data[++top] = data;
    obj->top = top;
    return;
}

void StackPop(Stack *obj)
{
    if (IsStackEmpty(obj) == true) {
        return;
    }
    void *data = obj->data[obj->top];
    if (data != NULL) {
        free(data);
        data = NULL;
    }
    obj->top--;
    return;
}

void *StackTop(Stack *obj)
{
    if (IsStackEmpty(obj) == true) {
        return NULL;
    }
    return (obj->data[obj->top]);
}

void StackClear(Stack *obj)
{
    if (IsStackEmpty(obj) == true) {
        return;
    }
    for (int i = 0; i <= obj->top; i++) {
        void *data = obj->data[i];
        if (data != NULL) {
            free(data);
            data = NULL;
        }
    }
    obj->top = -1;
    return;
}

void StackPushInt(Stack *obj, int value)
{
    int *node = (int *)malloc(sizeof(int));
    *node = value;
    StackPush(obj, node);
    return;
}

int StackTopInt(Stack *obj)
{
    if (IsStackEmpty(obj) == true) {
        return -1;
    }
    return *(int *)(obj->data[obj->top]);    
}

void StackPushStr(Stack *obj, char *str, int strSize)
{
    char *node = (char *)malloc(sizeof(char) * (strSize + 1));
    memcpy(node, str, strSize);
    node[strSize] = '\0';
    StackPush(obj, node);
    return;
}

char *StackTopStr(Stack *obj)
{
    if (IsStackEmpty(obj) == true) {
        return NULL;
    }
    return (char *)(obj->data[obj->top]);    
}

#define MAX_STACK_SIZE 100000
int* dailyTemperatures(int* T, int TSize, int* returnSize)
{
    int *ans = (int *)malloc(sizeof(int) * TSize);
    memset(ans, 0, sizeof(int) * TSize);
    Stack *monoStack = StackCreate(MAX_STACK_SIZE);
    for (int i = 0; i < TSize; i++) {
        int top = StackTopInt(monoStack);
        while (IsStackEmpty(monoStack) != true && T[top] < T[i]) {
            StackPop(monoStack);
            ans[top] = i - top;
            top = StackTopInt(monoStack);
        }
        StackPushInt(monoStack, i);
    }
    StackFree(monoStack);
    *returnSize = TSize;
    return ans;
}
```