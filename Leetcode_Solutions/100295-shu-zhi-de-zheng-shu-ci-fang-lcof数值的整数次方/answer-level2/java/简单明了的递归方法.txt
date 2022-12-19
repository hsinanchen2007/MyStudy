由于x^n可以对n分为奇数或者偶数处理：
    当n为奇数的时候x^n=x*(x*x)^(n/2)。
    当n为偶数的时候x^n=(x*x)^(n/2)。

所以代码可以写得很简洁
```
class Solution {
    public double myPow(double x, int n) {
        if(n ==0) return 1;
        if(n == 1) return x;
        if(n == -1) return 1/x;
        if((n & 1) == 1) return x * myPow(x*x, n>>1);
        return myPow(x*x, n>>1);
    }
}
```