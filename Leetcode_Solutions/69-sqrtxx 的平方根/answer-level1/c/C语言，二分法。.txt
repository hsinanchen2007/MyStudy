### 解题思路
简单二分法。
先设定区间【a，b】
初值a=0，b=x；
先比较中间值m，如果m平方大于x，说明平方根在前半段。缩小范围，b=m

如果m平方小于x，说明跟在后半部分，缩小范围，a=m

当m*m<=x 且（m+1）*（m+1）>x时，结束。

返回m

### 代码

```c
int mySqrt(int x){
    int ret=0;
    if(x==1)
    {
        return 1;
    }
    int a=0,b=x,m=0;
    while(1)
    {
        m=(a+b)/2;
        if((long long)m*m<=x)
        {
            if((long long)(m+1)*(m+1)>x)
            {
                ret=m;
                break;
            }
            a=m;
        }
        else
        {
            b=m;
        }
    }
    return ret;
}
```