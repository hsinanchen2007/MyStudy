
整数n可以表示为2进制，2进制每1位1都可以表示为2的对应位的次幂，如100=2^4，   111= 2^4 + 2^2 + 2^1
这个结果其实就是x的二项式和的次幂，按上面的例子就是x的(2^4 + 2^2 + 2^1)次幂，那么很显然，只要动态规划出
a[0]...a[1]...a[2].......a[30]的值（每个a都表示对应x的(2^i)次幂的值）即可，n做移位运算时，
遇到1就乘以a[n]，遇到0就什么都不做（因为是乘以x^0，也就是1）
为什么只到a[30]，因为a[31]是符号位呀，当遇到极限值INT_MIN时（最小负数），只需要求出最大正值，然后取倒数，再多除以1次x即可。
```
double a[32]; /* a[n]的值为x的2^n的结果 */
double Calc(double x, int n)
{
    int i;
    double res = 1.0;
    a[0] = x;
    for (i = 1; i < 31; i++) {
        if ((1 << i) <= n) { /* 超过n的a不用再计算了，用不上 */
            a[i] = a[i - 1] * a[i - 1];
        } else {
            a[i] = 1;
        }
    }
    if (n & 1 == 1) {
        res = x;
    }
    for (i = 1; i < 31; i++) {
        if (((1 << i) <= n) && (n & (1 << i)) != 0) {
            res = res * a[i];
        }
    }
    return res;
}
double myPow(double x, int n)
{
    double res = 1.0;
    if (n == 0) {
        return 1;
    }
    if (x == 0) {
        return 0;
    }
    if (n > 0) {
        return Calc(x, n);
    }
    if ((n < 0) && (n != INT_MIN)) {
        return 1 / Calc(x, 0 - n);
    }
    return (1 / Calc(x, 0 - (n + 1))) / x;
}
```
