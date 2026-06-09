### 解题思路
这道题我想和它的[反问题](https://leetcode-cn.com/problems/excel-sheet-column-title/solution/chun-cjie-jue-26jin-zhi-zhuan-huan-by-wei-ai-mai-x/)一起讨论，大家也可以通过链接跳转过去看看。

这道题的本质其实就是`26进制`
但是又有区别：`这里的数是从1开始的，并不是常规的0`

那么就会导致新的问题：`余数的最高其实是26，最低其实是1`

同时又会保持同样的性质不变:`仍然是满26进1`

这里给出常规的N进制转10进制的代码：
```
while size()!=0
    do Interger:last=str[--size]-'0'
    sum=sum+last*base;
    base=base*N
end
```



### 代码

```c
int titleToNumber(char * s){
    int length=strlen(s);
    if(length==0)
    return 0;
    int sum=0;
    long base=1;
    while(length)
    {
        sum+=(s[--length]-'A'+1)*base;
        base*=26;
    }
    return sum;
}
```