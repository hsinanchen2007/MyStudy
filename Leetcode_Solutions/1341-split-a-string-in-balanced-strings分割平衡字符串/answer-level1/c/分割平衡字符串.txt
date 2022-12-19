### 解题思路
有点像匹配括号，用栈解决
每次栈空计数器加一即可。

### 代码

```c
int balancedStringSplit(char * s){
    int length=0;
    for(char*iter =s;*iter!='\0';++iter)
        ++length;

    char *stack=(char*)malloc(sizeof(char)*(length+1));
    int top=-1;

    int sum=0;
    while(*s!='\0')
    {
        stack[++top]=*s++;
        while(top!=-1)
        {
            if(stack[top]==*s)
                stack[++top]=*s;
            else
                top--;
            ++s;            
        }
        ++sum;
    }

    free(stack);

    return sum;
}
```