### 解题思路
    思路很简单，就是将整数转化为字符串进行操作，去符号，去尾0，然后判断是否溢出即可。代码写的挺乱的还加了特判，回头再来改啦==

### 代码

```c
int reverse(int x)
{
    char str[100];
    int ans = 0;
    int sig = 0;   //0为正数，1为负数
    if(x == 0) return 0;
    if(x < 0)
    {
        sig = 1; 
        if(x == -2147483648) return 0;
        sprintf(str,"%d",-x);  //str中保存绝对值
    }
    else
        sprintf(str,"%d",x);

    int len = strlen(str);
    int pos =len-1;
    while(pos > 0) 
    {
        if(str[pos] == '0')
        {
            str[pos] = 0;
            pos--;
            len--;
        }
        else
            break;
    }

    for(int i = 0; i < len/2; i++)
    {
        char p;
        p = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = p;
    }

    if(len == 10)   //10位以下不会溢出
    {
        if(sig == 1) 
        {
            if(strcmp(str,"2147483648") > 0) return 0;
        }
        else
        {
            if(strcmp(str,"2147483647") > 0) return 0;
        }
    }
    
    ans = atoi(str);
    ans = sig == 1 ? -ans : ans;
    return ans;
}
```