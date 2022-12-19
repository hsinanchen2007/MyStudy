## **1. 牛顿迭代**
求n的平方根，即求函数f(x) = x^2 - n的零点。
由牛顿迭代法得，x(n+1) = x(n) - f(x) / f(x)导 = (x + n / x) / 2。

```
int mySqrt(int x){
    if(x == 0)
        return 0;
    if(x == 1)
        return 1;
    long long y = x / 2;
    while(y * y > x){
        y = (y + x / y) / 2;

    }
    return y;
}