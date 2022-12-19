### 解题思路


### 代码

```c
char *removeKdigits(char *num, int k)
{
    int i;
    int top = 0;        // 栈底
    int length;     // 总共的num数量
    length = strlen(num);
    if(length == k)
        return "0";
    int *stack=(int *)malloc(sizeof(int)*(length+1));  
    memset(stack, 0, length+1);  
    // 最后一位存放结束符'\0'
    for(i = 0 ;i < length; ++i)
    {
        int number = num[i] - '0';
        while(top != 0 && k != 0 && stack[top-1] > number)    // 出栈
        {
            stack[--top];
            k--;
        }
        if(number != 0 || top != 0)     // 保证 0 不是首数字 
        {
            stack[top++] = number;               // 进栈
        }               
    }
    while(top != 0 && k != 0)           // 栈不空 且 k 不为0
    {
        top--;
        k--;
    }
    for(i = 0;i <= top ; ++i)           // 将stack数字转换为字符输出
    {
        num[i] = stack[i] + '0';
    }
    num[top] = '\0';    
    if(strlen(num) == 0)    // 如果数据空 即返回“0”
        num = "0";
    return num;
}
```