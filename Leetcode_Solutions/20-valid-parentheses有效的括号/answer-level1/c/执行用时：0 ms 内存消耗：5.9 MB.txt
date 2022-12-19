### 解题思路
左括号入栈，如果遇到右括号或其他就与栈顶左括号比较是否匹配，不匹配则返回false。
最后若栈不为空，说明有的左括号没有匹配成功，也返回false。

### 代码

```c
struct Stack
{
    int top;
    char index[10000];
};

//入栈
void stack_push(char e,struct Stack *stack)
{
    ++stack->top;
    stack->index[stack->top] = e;
}

//出栈
void stack_pop(struct Stack *stack)
{
    stack->top--;
}

char stack_top(struct Stack *stack)
{
    return stack->index[stack->top];
}

bool stack_empty(struct Stack *stack)
{
    if(stack->top==-1)
        return true;
    else
        return false;
}

bool isValid(char * s)
{
    struct Stack *stack = NULL;
    stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top=-1;
 
    while(*s!='\0')
    {
        
        if(*s=='('||*s=='['||*s=='{')
        {
            stack_push(*s,stack);
      
        }

        else
        {
            char c = stack->index[stack->top];
            printf("%c",c);
            switch(*s)
            {
                case ')':
                    stack_pop(stack); if(c!='(') return false; break;
                case ']':
                    stack_pop(stack); if(c!='[') return false; break;
                case '}':
                    stack_pop(stack); if(c!='{') return false; break;
                default:
                    break;
            }
        }
        s++;
    }

    if(!stack_empty(stack))
        return false;
    else
        return true;
}
```