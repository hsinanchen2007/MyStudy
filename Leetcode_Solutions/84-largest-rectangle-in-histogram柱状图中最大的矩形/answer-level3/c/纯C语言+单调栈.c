```
int g_top;
int *g_stack = NULL;

int InitStack(int stackSize)
{
    g_top = -1;

    g_stack = (int *)malloc(sizeof(int) * stackSize);
    if (g_stack == NULL) {
        return -1;
    }
    (void)memset(g_stack, 0, sizeof(int) * stackSize);

    return 0;
}

void DestoryStack()
{
    if (g_stack != NULL) {
        free(g_stack);
        g_stack = NULL;
    }
}

int GetStackSize()
{
    return g_top + 1;
}

void Push(int input)
{
    g_stack[++g_top] = input;
}

void Pop()
{
    g_stack[g_top] = 0;
    g_top--;
}

int GetTop()
{
    if (g_top != -1) {
        return g_stack[g_top];
    }

    return 0;
}

#define MAX(a, b) (a) > (b) ? (a) : (b)

int largestRectangleArea(int* heights, int heightsSize){
    if (heightsSize == 0 || heights == NULL) {
        return 0;
    }

    int max;
    int temp;
    int top;
    int ret;
    int len;
    int *array = NULL;

    ret = InitStack(heightsSize + 1);
    if (ret != 0) {
        return 0;
    }

    array = (int *)malloc(sizeof(int) * (heightsSize + 1));
    if (array == NULL) {
        DestoryStack();
        return 0;
    }
    (void)memcpy(array, heights, sizeof(int) * (heightsSize));
    array[heightsSize] = 0;
    max = 0;

    for (int i = 0; i <= heightsSize; i++) {
        while (GetStackSize() != 0 && array[i] < array[GetTop()]) {
            top = GetTop();
            Pop();
            if (GetStackSize() == 0) {
                len = i;
            } else {
                len = i - GetTop() - 1;
            }

            temp = array[top] * len;
            max = MAX(max, temp);
        }

        Push(i);
    }

    free(array);
    DestoryStack();

    return max;
}
```
