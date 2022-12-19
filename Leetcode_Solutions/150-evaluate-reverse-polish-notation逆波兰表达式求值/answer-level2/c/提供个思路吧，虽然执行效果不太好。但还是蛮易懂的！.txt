```
int evalRPN(char ** tokens, int tokensSize){

    int i;
    int res;
    int top = -1;
    int *stack = (int *)malloc(sizeof(int) * tokensSize );
    if(!stack)
        exit(EXIT_FAILURE);
    
    for(i=0; i<tokensSize; i++)
    {
        if(tokens[i][0] == '0') // 0字符串要特殊考虑。
            stack[++top] = 0;
        if(res = atoi(tokens[i])) //如果当前字符串是数字
            stack[++top] = res;
        else                      // 如果当前字符串是操作符
            switch(tokens[i][0])  
            {
                case '+' : res = stack[top--]; res = stack[top] + res; stack[top] = res; break;
                case '-' : res = stack[top--]; res = stack[top] - res; stack[top] = res; break;
                case '*' : res = stack[top--]; res = stack[top] * res; stack[top] = res; break;
                case '/' : res = stack[top--]; res = stack[top] / res; stack[top] = res; break; 
            }
    }

    return stack[top];
}
```
