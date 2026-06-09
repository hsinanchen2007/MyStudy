```

#define MAX_LEN 10000

int stack[MAX_LEN];
int *top;

void initStack()
{
    top = stack;
}

bool empty()
{
    return top == stack;
}

void push(int num)
{
    *top++ = num;
}

int pop()
{
    return *(--top);
}

bool isDigit(char c)
{
    return c <= '9' && c >= '0';
}

int evalRPN(char ** tokens, int tokensSize){

    initStack();

    for(int i = 0; i < tokensSize; i++)
    {
        char numBuf[10];
        memset(numBuf, 0, 10);

        int sign = 1;
        char *cur = tokens[i];

        while(*cur)
        {
            if(isDigit(*cur))    numBuf[strlen(numBuf)] = *cur;
            else if(*cur == '-') sign = -1;

            cur++;
        }

        if(strlen(numBuf))
        {   // this is a number token
            push(atoi(numBuf) * sign);
        }
        else
        {   // this is a operator token
            assert(!empty());
            int num1 = pop();
            int num2 = pop();

            switch(tokens[i][0])
            {
                case '+':
                    push(num1 + num2);
                    break;
                case '-':
                    push(num2 - num1);
                    break;
                case '*':
                    push(num1 * num2);
                    break;
                case '/':
                    push(num2 / num1);
                    break;
                default:
                    assert(0);
                    break;
            }
        }
    }

    assert(!empty());
    return pop();
}

```
