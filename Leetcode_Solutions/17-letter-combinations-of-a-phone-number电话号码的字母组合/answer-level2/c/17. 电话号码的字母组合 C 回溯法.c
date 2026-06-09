### 解题思路
回溯思路很容易理解，深度上数字索引，每个数字最多有4个孩子

### 代码

```c
#define MAX_SIZE    10000

typedef struct tagStack {
    char *array;
    int index;
    int size;
} Stack;

typedef struct tagBt {
    char **array;
    int index;
    int size;
} Bt;

typedef struct tagStep {
    int numIndex; /* 数字索引 */
    int charIndex; /* 单个数字中字符索引 ， 没有用的 */
} Step;

#define MAX_NUM             9
#define PER_MAX_CNT         4
char g_mapping[MAX_NUM][PER_MAX_CNT] = {
    {'a', 'b', 'c', '0'},
    {'d', 'e', 'f', '0'},
    {'g', 'h', 'i', '0'},
    {'j', 'k', 'l', '0'},
    {'m', 'n', 'o', '0'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v', '0'},
    {'w', 'x', 'y', 'z'}
};

int InitStack(Stack *stack, int size)
{
    stack->array = (char *)malloc(size);
    if (stack->array == NULL) {
        return -1;
    }
    memset(stack->array, 0, size);

    stack->size = size;

    return 0;
}

int InitBt(Bt *bt)
{
    bt->array = (char **)malloc(sizeof(char *) * MAX_SIZE);
    if (bt->array == NULL) {
        return -1;
    }
    memset(bt->array, 0, sizeof(char *) * MAX_SIZE);

    bt->size = MAX_SIZE;
    bt->index = 0;

    return 0;
}

void PushStack(Stack *stack, char data)
{
    if (stack->index >= stack->size) {
        return;
    }

    int index = stack->index;
    stack->array[index] = data;
    stack->index++;

    return;
}

void PopStack(Stack *stack)
{
    if (stack->index <= 0) {
        return;
    }

    stack->index--;

    return;
}

void AddRecord(Stack *stack, Bt *bt)
{
    if (bt->index >= bt->size || stack->size <= 0) {
        return;
    }

    bt->array[bt->index] = (char *)malloc((stack->index + 4));
    if (bt->array[bt->index] == NULL) {
        return;
    }
    memset(bt->array[bt->index], 0, stack->index + 4);

    for (int i = 0; i < stack->index; i++) {
        bt->array[bt->index][i] = stack->array[i];
    }
    bt->index++;

    return;
}

void BackTracing(char * digits, int size, Step step, Stack *stack, Bt *bt)
{
    if (step.numIndex == size) {
        AddRecord(stack, bt);
        return;
    }

    int digitIndex = digits[step.numIndex] - '2';
    for (int i = 0; i < PER_MAX_CNT; i++) {
        if (g_mapping[digitIndex][i] == '0') {
            continue;
        }

        PushStack(stack, g_mapping[digitIndex][i]);
        
        Step nextStep = {
            .numIndex = step.numIndex + 1,
            .charIndex = step.charIndex + 1
        };
        BackTracing(digits, size, nextStep, stack, bt);

        PopStack(stack);
    }

    return;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    if ((digits == NULL) || (returnSize == NULL) || (digits[0] == '0')) {
        return NULL;
    }

    Stack stack = {0};
    int len = strlen(digits);
    int ret = InitStack(&stack, len);
    if (ret != 0) {
        return NULL;
    }
    
    Bt bt = {0};
    ret = InitBt(&bt);
    if (ret != 0) {
        free(stack.array);
        return NULL;
    }

    Step step = {0};
    BackTracing(digits, len, step, &stack, &bt);

    free(stack.array);

    *returnSize = bt.index;
    return bt.array;
}
```