#define STACK_SIZE 31000
typedef struct {
    int ele[STACK_SIZE];
    int top;
} Stack;

void Push(Stack *stk, int tempIdx)
{
    if (stk->top < STACK_SIZE) {
        stk->ele[stk->top] = tempIdx;
        stk->top++;
    }
}

int Pop(Stack *stk)
{
    if (stk->top > 0) {
        return stk->ele[--stk->top];
    }

    return -1; // 表示空栈
}

int StackTopEle(Stack *stk)
{
    int top = stk->top;
    return stk->ele[--top];
}


Stack g_stack;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    memset((void*)&g_stack, 0, sizeof(g_stack));

    int *result = (int *)malloc(sizeof(int) * TSize);
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }
    memset(result, 0, sizeof(int) * TSize);

    int i;
    int temperIdx;
    for (i = 0; i < TSize; i++) {
        if (g_stack.top == 0 || T[i] <= T[StackTopEle(&g_stack)]) {
            Push(&g_stack, i); // 温度索引入栈
            continue;
        }

        while (g_stack.top > 0 && (T[i] > T[StackTopEle(&g_stack)])) {
            temperIdx = Pop(&g_stack);
            if (temperIdx != -1) {
                result[temperIdx] = i - temperIdx;
            }
        }
        Push(&g_stack, i);
    }

    *returnSize = TSize;
    return result;
}