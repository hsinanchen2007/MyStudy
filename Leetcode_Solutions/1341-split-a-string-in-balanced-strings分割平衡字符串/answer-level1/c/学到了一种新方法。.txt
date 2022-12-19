### 解题思路
类似于发牌的情景，左边牌为'L'，右边牌为'R',从左向右遍历整个字符串，得到字符串长度。
然后利用for循环遍历，每逢遇到'R'，a加一，反之b加一。再用while循环判断a是否等于b且不等于0，若满足则sum加一，最终返回sum的值。a,b初始值都为0.

### 代码

```c
int balancedStringSplit(char * s){
    char* p=s;
    int sum=0;
    int cnt=0;
    int a=0,b=0;
    while(*p)
    {
        cnt++;
        p++;
    }
    for(int i=0;i<cnt;i++)
    {
        if(s[i]=='R')
        {
            a++;
        }
        else
        {
            b++;
        }
        while(a==b)
        {
            sum++;
            break;
        }
    }
    return sum;
}
```