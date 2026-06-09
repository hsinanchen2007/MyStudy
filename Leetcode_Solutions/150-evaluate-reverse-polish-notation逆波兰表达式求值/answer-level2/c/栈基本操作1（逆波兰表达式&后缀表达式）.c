### 解题思路
如果是复杂计算器，可以考虑用状态机来做，避免过多的if、else。

### 代码

```c
#define MAXSIZE 10000
int strToInt(char *num)
{
    unsigned long len = strlen(num);
    int iNum = 0;
    int isNegative = 0;
    
    for (int i = 0; i < len; i ++)
    {
        if (num[i] == '-')
        {
            isNegative = 1;
            continue;
        }
        
        iNum = iNum * 10 + (num[i] - '0');
    }
    
    if (isNegative)
    {
        iNum = 0 - iNum;
    }

    return iNum;
}

int evalRPN(char ** tokens, int tokensSize){
    int *stack;
    stack = (int *)malloc(sizeof(int) * MAXSIZE);
    memset (stack, 0, sizeof(int) * MAXSIZE);
    int top = -1;
    int tmp;

    int res = -1;

    for (int i = 0; i < tokensSize; i ++)
    {
        tmp = 0;
        if (!strcmp(tokens[i], "+"))
        {
            tmp = stack[top - 1] + stack[top];
            top --;
            stack[top] = tmp;
        }
        else if (!strcmp(tokens[i], "-"))
        {
            tmp = stack[top - 1] - stack[top];
            top --;
            stack[top] = tmp;
        }
        else if (!strcmp(tokens[i], "*"))
        {
            tmp = stack[top - 1] * stack[top];
            top --;
            stack[top] = tmp;
        }
        else if (!strcmp(tokens[i], "/"))
        {
            tmp = stack[top - 1] / stack[top];
            top --;
            stack[top] = tmp;
        }
        else
        {
            if (top < MAXSIZE - 1)
            {
                stack[++top] = strToInt(tokens[i]);
            }
            
        }

    }
    if (top != -1)
        res = stack[top];

    return res;

}
```