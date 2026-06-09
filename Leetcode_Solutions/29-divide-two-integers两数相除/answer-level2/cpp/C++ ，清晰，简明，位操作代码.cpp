两数相除，关键点有：
1） INT-MIN / -1 = INT_MAX
2)  除数与被除数使用绝对值，用long来表示，正负号先判别出来
3)  结果是以二进制的方式累加的


```
int divide(int dividend, int divisor) {
    if (divisor == 0)
        return -1;
    if (dividend == 0)
        return 0;
    if (dividend == INT_MIN || divisor == -1)
        return INT_MAX;

    long ldividend = labs(dividend), ldivisor = labs(divisor), res = 0;
    int sign = (dividend > 0 ^ divisor > 0)?-1:1;

    while (ldividend >= ldivisor)
    {
        long p = 1, c = ldivisor;
        while (ldividend >= c<< 1)
        {
            c <<= 1;
            p <<= 1;
        }
        res += p;
        ldividend -= c;
    }
    return sign * res;
}
```
