0ms, 5.9MB,感觉C语言麻烦在对空格一些特殊情况的处理，我每次往返回结果的数组res里存字符的时候，先判断是否为第一次存，若是则不用在单词前面加空格，若不是则先加一个空格。

```
char* reverseWords(char* s){
    int len = strlen(s);
    char *res = (char *)malloc(sizeof(char) * (len+1));
    int i, count = 0, j = 0, flag = 0;
    for(i = len - 1;i >= 0;i--)
    {
        if(s[i] != ' ')
        {
            count++;
        }
        else if(s[i] == ' '&&count !=0)
        {
            if(i != 0&&flag != 0)
            {
                res[j++] = ' ';
            }
            int x = count;
            while(count)
            {
                res[j++] = s[i + x - count + 1];
                count--;
            }
            flag = 1;
            count = 0;
        }
    }
    if(count != 0)
    {
        if(flag == 1)
        {
            res[j++] = ' ';
        }
        int x = count;
        while(count)
        {
            res[j++] = s[i + x - count + 1];
            count--;
        }
    }
    
    res[j] = '\0';
    return res;
}
```
