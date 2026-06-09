### 解题思路
用两个栈实现一个队列
栈：先进后出
队列：先进先出
思路：只有当辅助栈为空时才能往辅助栈中加数据，要不然后破坏数据的先后顺序

### 代码

```c
/* 用两个栈实现一个队列 */
#define MAX_SIZE 1000
typedef struct {
    int top;
    int arr[MAX_SIZE];
} Stack;

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }

    stack->top = -1;
    memset(stack->arr, 0x0, sizeof(int) * MAX_SIZE);
    return stack;
}

void push(Stack *stack, int val)
{
    if ((stack == NULL) || (stack->top >= MAX_SIZE)) {
        return;
    }

    stack->arr[++stack->top] = val;
    return;
}

int pop(Stack *stack)
{
    if ((stack == NULL) || (stack->top == -1)) {
        return INT_MAX;
    }

    return stack->arr[stack->top--];
}

int isEmpty(Stack *stack)
{
    if (stack == NULL) {
        return 1; // 1表示栈为空
    }

    return stack->top == -1 ? 1 : 0;
}

typedef struct {
    Stack *dataStack;
    Stack *helpStack;
} CQueue;


CQueue* cQueueCreate() {
    CQueue *queue = (CQueue *)malloc(sizeof(CQueue));
    if (queue == NULL) {
        return NULL;
    }

    queue->dataStack = createStack();
    queue->helpStack = createStack();
    return queue;
}

void cQueueAppendTail(CQueue* obj, int value) {
    if (obj == NULL) {
        return;
    }

    push(obj->dataStack, value);
    return;
}

int cQueueDeleteHead(CQueue* obj) {
    if (obj == NULL) {
        return -1;
    }

    int tmp;
    if (isEmpty(obj->helpStack) == 1) {
        while (isEmpty(obj->dataStack) != 1) {
            tmp = pop(obj->dataStack);
            push(obj->helpStack, tmp);
        }
    }

    return isEmpty(obj->helpStack) == 1 ? -1 : pop(obj->helpStack);
}

void cQueueFree(CQueue* obj) {
    if (obj == NULL) {
        return;
    }

    if (obj->dataStack != NULL) {
        free(obj->dataStack);
    }

    if (obj->helpStack != NULL) {
        free(obj->helpStack);
    }

    free(obj);
    return;
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/
```