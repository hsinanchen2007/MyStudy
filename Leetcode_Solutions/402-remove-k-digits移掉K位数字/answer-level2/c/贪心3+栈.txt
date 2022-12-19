### 解题思路
此处撰写解题思路

### 代码

```c
char * removeKdigits(char * num, int k){
    int len = strlen(num);
    int top = -1;
    char *stack;

    stack = (char *)malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i ++)
    {
        while (top != -1 && stack[top] > num[i] && k > 0)
        {
            top --;
            k --;
        }
        if (num[i] != '0' || top != -1)
        {
            stack[++top] = num[i];
        }
    }

    while (k > 0 && top > -1)
    {
        top --;
        k --;
    }

    if (top == -1)
    stack[++top] = '0';
    
    stack[++top] = '\0';

    return stack;
}
```