### 解题思路
自己写堆栈，这题还好未考虑优先级问题，如果有优先级会复杂很多

### 代码

```c

typedef struct{
    char *data;
    int capacity;
    int top;
} Stack;

void init(Stack * s, int capacity)
{
    s->data = (char *)malloc(sizeof(char)*(capacity + 1));
    s->capacity = capacity;
    s->top = -1;
}

void push(Stack * s, char e)
{
    s->data[++s->top] = e;
}
void pop(Stack *s)
{
    s->top--;
}

char top(Stack * s)
{
    return s->data[s->top];
}

bool isValid(char * s){
    Stack stack;
    int n = strlen(s);
    init(&stack, n);
    for(int i = 0; i < n; i++){
        switch(s[i]){
            case '(' :
            case '[' :
            case '{' : push(&stack, s[i]); break;
            case ')' :
            case ']' :
            case '}' : {
                if(stack.top == -1) return false;
                char e = top(&stack);
                if(e == '(' && s[i] == ')') pop(&stack);
                else if(e == '[' && s[i] == ']') pop(&stack);
                else if(e == '{' && s[i] == '}') pop(&stack);
                else return false;
                break;
            }
            default: break;
        }
    }

    if(stack.top == -1) return true;
    else return false;
}
```