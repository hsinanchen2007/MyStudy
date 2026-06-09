### 解题思路
模拟按照笔算乘法算式， 两轮循环

### 代码

```c
char * multiply(char * num1, char * num2){
    int i = 0, j = 0, len1 = 0, len2 = 0;
    int t = 0, value = 0, n = 0, m = 0;
    char   result[110*110];
    char  * p = NULL;
    memset(result , 0x00, sizeof(result));
    len1 = strlen(num1);
    len2 = strlen(num2);
    if(strncmp(num1, "0",1) == 0 || strncmp(num2, "0",1) == 0)
        return "0";
    memset(result, '0', len2+len1);
    n=len1+len2-1;
    m=n;
    for(i=len1-1;i>=0;i--, m--)
    {
        for(j=len2-1, n=m;j>=0;j--, n--)
        {
            t = (result[n] - '0')+(num1[i] - '0') * (num2[j] - '0');
            result[n] = t%10 + '0';
            if(t>=10)
            {
                value = result[n-1] - '0';
                result[n-1]=(value + t/10) + '0';
            }
        }
    }
    result[len1+len2] = 0;
    p = result ;
    if(result[0] == '0')
        p = result + 1;
    
    return p ; 
}
```