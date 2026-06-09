#define MAXSIZE 10000

typedef struct stack {
    char data[MAXSIZE];
    int top;
} stack;

void stack_init(stack *s)
{
    memset(s->data, 0, sizeof(char) * MAXSIZE);
    s->top = -1;
}

void stack_pop(stack *s)
{
    if (s->top == -1) {
        return;
    }
    s->top--;
}

char stack_top(stack *s)
{
    if (s->top == -1) {
        return -1;
    }

    return s->data[(s->top)];
}

void stack_push(stack *s, int data)
{
    if (s->top == MAXSIZE) {
        return;
    }
    s->data[++(s->top)] = data;
}

bool isValid(char * s){
    stack S;
    char *str = s;

    stack_init(&S);

    while (*str != '\0') {
        if (*str == '{' || *str == '[' || *str == '(') {
            stack_push(&S, *str);
        } else if (*str == '}') {
            if (stack_top(&S) == '{') {
                stack_pop(&S);
            } else {
                stack_push(&S, *str);
            }
        } else if (*str == ']') {
            if (stack_top(&S) == '[') {
                stack_pop(&S);
            } else {
                stack_push(&S, *str);
            }
        } else if (*str == ')') {
            if (stack_top(&S) == '(') {
                stack_pop(&S);
            } else {
                stack_push(&S, *str);
            }
        }
        str++;
    }
    if ((&S)->top == -1) {
        return true;
    }
    return false;
}

