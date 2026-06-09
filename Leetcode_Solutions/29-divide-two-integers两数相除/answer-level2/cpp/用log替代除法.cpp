算是一种比较投机取巧的办法。
因为`log(a/b)=log(a)-log(b)`，所以`a/b = pow(2, log2(a)-log2(b))`
为了解决溢出问题，需要用到long。当然，也可以单独判断除数为1或者-1的方法。
代码如下：
``` c++
class Solution {
public:
    int divide(int dividend, int divisor) {
        long a, b;
        bool sign = false;
        a = dividend;
        b = divisor;
        if(a<0)
        {
            a = -a;
            sign = !sign;
        }
        if(b<0)
        {
            b = -b;
            sign = !sign;
        }

        long val = pow(2, log2l(a)-log2l(b));
        if(sign)
            val = -val;
        if(val>=INT_MAX||val<INT_MIN)
            return INT_MAX;
        return val;
    }
};
```
