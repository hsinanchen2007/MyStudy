### 解题思路
效率比较低

### 代码

```c
#define MAX_LEN 1000

typedef struct {
    int top;
    int arr[MAX_LEN];
} Stack;

Stack *newStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }

    stack->top = -1;
    memset(stack->arr, 0x0, sizeof(stack->arr));
    return stack;
}

void push(Stack *stack, int val)
{
    if ((stack == NULL) || (stack->top >= MAX_LEN)) {
        return;
    }

    stack->arr[++stack->top] = val;
    return;
}

int pop(Stack *stack)
{
    if ((stack == NULL) || (stack->top == -1)) {
        return -1;
    }

    return stack->arr[stack->top--];
}

int getPeer(Stack *stack)
{
    if (stack == NULL) {
        return -1;
    }

    return stack->arr[stack->top];
}

int isEmpty(Stack *stack)
{
    if (stack == NULL) {
        return 1; 
    }

    return stack->top == -1 ? 1 : 0;
}

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
{
    if (pushedSize != poppedSize) {
        return false;
    }

    if ((pushedSize == 0) && (poppedSize == 0)) {
        return true;
    }

    if ((pushedSize == 0) || (poppedSize == 0)) {
        return false;
    }
    Stack *stack = newStack();
    int i = 1;
    int j = 0;
    push(stack, pushed[0]);

    while ((i <= pushedSize) && (j < poppedSize)) {
        if (getPeer(stack) == popped[j]) {
            pop(stack);
            j++;
            printf("j = %d\n", j);
            continue;
        }

        if ((i == pushedSize) && (getPeer(stack) != popped[j])) {
            return false;
        }
        
        if (i != pushedSize) {
            push(stack, pushed[i++]);
            printf("i = %d\n", i);
        }
    }

    return isEmpty(stack);
}
```