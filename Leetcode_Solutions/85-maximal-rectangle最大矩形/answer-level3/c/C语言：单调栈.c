### 解题思路
![image.png](https://pic.leetcode-cn.com/dd7d0b6e71bb5fdfad37502174cd09f2fb393dc0be3a8bdb6cfbbfb750ca052d-image.png)


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
    free(data);
    data = NULL;
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

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maximalRectangle(char **matrix, int matrixSize, int *matrixColSize)
{
    int **height = (int **)malloc(sizeof(int *) * matrixSize);
    for (int i = 0; i < matrixSize; i++) {
        height[i] = (int *)malloc(sizeof(int) * (matrixColSize[i] + 1));
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (i == 0) {
                height[i][j] = (matrix[i][j] == '1') ? 1 : 0;
            } else {
                height[i][j] = (matrix[i][j] == '1') ? (height[i - 1][j] + 1) : 0;
            }
        }
        height[i][matrixColSize[i]] = 0;
    }

    Stack *monotoneStack = StackCreate(matrixSize * matrixSize);
    int ans = 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j <= matrixColSize[i]; j++) {
            while ((IsStackEmpty(monotoneStack) != true) && 
                    (height[i][*(int *)monotoneStack->data[monotoneStack->top]] >= height[i][j])) {
                int h = height[i][*(int *)monotoneStack->data[monotoneStack->top]];
                StackPop(monotoneStack);
                int sidx = ((IsStackEmpty(monotoneStack) == true) ? -1 : *(int *)(monotoneStack->data[monotoneStack->top]));
                ans = MAX(ans, h * (j - sidx - 1));
            }
            int *node = (int *)malloc(sizeof(int));
            *node = j;
            StackPush(monotoneStack, node); 
        }
        StackClear(monotoneStack);
    }

    StackFree(monotoneStack);
    return ans;
}
```