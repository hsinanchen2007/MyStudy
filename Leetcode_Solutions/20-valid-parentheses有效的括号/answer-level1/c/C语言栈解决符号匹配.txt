```
// 定义栈元素
typedef struct CharElmt_ {
    char val;
    struct CharElmt_ *next;
} CharElmt;

// 定义栈
typedef struct Stack_ {
    int size;
    CharElmt *top;
} Stack;

// 压栈操作
void push(Stack *stack, const char data) {
    CharElmt *element;
    element = (CharElmt *)malloc(sizeof(CharElmt));
    element->val = data;

    if (stack->size == 0) {
        stack->top = element;
        element->next = NULL;
    }
    else {
        element->next = stack->top;
        stack->top = element;
    }
    stack->size++;
    return;
}

//出栈操作
void pop(Stack *stack) {
    CharElmt *element;
    element = stack->top;

    if (stack->size == 1) {
        stack->top = NULL;
    }
    else {
        stack->top = stack->top->next;
    }
    free(element);
    stack->size--;
    return;
}

// 销毁栈
void stack_destroy(Stack *stack) {
    while(stack->size != 0) {
        pop(stack);
    }
    memset(stack, 0, sizeof(Stack));
    return;
}

// 查看栈顶元素
#define stack_peek(stack) (stack->top == NULL ? NULL : stack->top->val)

bool isValid(char * s){
    if (*s == '\0') return 1;

    char *tmp;

    // 初始化栈
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->size = 0;
    stack->top = NULL;

    tmp = s;
    push(stack, *tmp);

    while (*(++tmp) != '\0') {
        if (stack_peek(stack) + 1 == *tmp || stack_peek(stack) + 2 == *tmp) {
            if (stack->size != 0) {
                pop(stack);
            }
            else {
                if (*(tmp + 1) != '\0') {
                    tmp++;
                    push(stack, *tmp);
                }
            }
        }
        else {
            push(stack, *tmp);
        }
    }

    if (stack->size == 0) {
        stack_destroy(stack);
        return 1;
    }
    else {
        stack_destroy(stack);
        return 0;
    }
}
```
