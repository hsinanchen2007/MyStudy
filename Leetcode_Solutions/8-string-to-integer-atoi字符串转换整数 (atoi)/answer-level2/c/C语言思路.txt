### 解题思路
C语言
1、先找到第一个非空位置
2、若为负号，标志位置-1，后移一位
3、然后找到连续的数字，记录位置j
4、最后转换字符为数字
菜鸟思路，若有错误，望指正
### 代码

```c
int myAtoi(char * str){
    long ret=0;
    int i=0;
    int flag=1;
    while(str[i]==' ') i++;
    if(str[i]=='-') flag=-1;
    if(str[i]=='-'||str[i]=='+') i++;
    if('0'<=str[i]&&str[i]<='9')
    {
        int j=i+1;
        while(('0'<=str[j]&&str[j]<='9')&&j<strlen(str)) j++;
        for(int t=i;t<j;t++)
        {
            ret=ret*10+str[t]-'0';
            if(flag*ret>INT_MAX)
                return INT_MAX;
            if(flag*ret<INT_MIN)
                return INT_MIN;
            continue;
        }      
    }
    else
        return 0;
    return ret*flag;
}
```