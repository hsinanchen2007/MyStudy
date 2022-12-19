解题思路 逆序可以考虑一下栈，不是空格就入栈，是空格就出栈，判断好首尾空格，很简单的

```
char * reverseWords(char * s){
    int len = strlen(s);
    if(len == 0)
        return s;
    char *res = (char *)malloc(sizeof(char) * (strlen(s) + 2));
    char *stack = (char *)malloc(sizeof(char) * (strlen(s) + 2));
    int i, t = 0, count = 0, flag = 0;
    for(i = len - 1;i >= 0;i--)
    {
        if(s[i] != ' ')
        {
            stack[t++] = s[i];
            flag = 1;
        }
        if(s[i] == ' ')
        {
            while(t > 0)
                res[count++] = stack[--t];
            if(flag == 1)
                res[count++] = ' ';
            flag = 0;
        }
    }
    if(t == 0)
    {
        if(count > 0)
            count--;
    }
    while(t > 0)
        res[count++] = stack[--t];
    res[count] = '\0';
    return res;
}
```
