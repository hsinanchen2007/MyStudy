### 解题思路
尝试入栈前先看下栈顶是否跟本元素一样，如果一样那么弹出，如果不一样，压入。

### 代码

```c
#define MAXLENGTH 20000
#define ERR 1
#define OK 0

struct stack {
    char * top;
    char * botom;
    char * array;
    int size;
    int cnt;
};

int push(struct stack* stack, char element)
{
    if (stack->cnt == stack->size) {
        return ERR;
    }
    if (stack->cnt != 0) {
        stack->top++;
    }
    *(stack->top) = element;
    stack->cnt++;
    return OK;
}

int pop(struct stack* stack)
{
    if (stack->cnt == 0) {
        return ERR;
    }
    *(stack->top) = '\0';
    stack->cnt--;
    if (0 != stack->cnt) {
        stack->top--;
    }
    return OK;
}

char peak(struct stack* stack)
{
    return *(stack->top);
}

void initStack(struct stack* stack)
{
    stack->top = stack->array;
    stack->botom = stack->array;
    stack->cnt = 0;
    stack->size = MAXLENGTH;
    return;
}

char * removeDuplicates(char * S){
    char* tmp = S;
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    memset(stack, 0, sizeof(struct stack));
    stack->array = (char *)malloc(sizeof(char) * MAXLENGTH);
    memset(stack->array, 0, sizeof(char) * MAXLENGTH);

    initStack(stack);
    if ((S == NULL) || (*S == '\0')) {
        return S;
    }

    for (; *tmp != '\0'; tmp++) {
        //尝试入栈前先看下栈顶是否跟本元素一样，如果一样那么弹出，如果不一样，压入。
        if (*tmp == peak(stack)) {
            pop(stack);
        } else {
            push(stack, *tmp);
        }
    }
    memset(S, 0, strlen(S) + 1);
    memmove(S, stack->botom, strlen(stack->botom));
    free(stack->array);
    free(stack);
    return S;
}
```