### 解题思路

Java要注意溢出

### 代码

```java
class Solution {
    // 使用快速幂
    // x^i = x^(i/2) * x^(i/2) * x;
    public double myPow(double x, int n) {
        if (x == 0) return 0;
        long nTemp = n;
        if (n < 0) {
            x = 1 / x;
            nTemp = -nTemp;
        }
        // n / 2
        return getPow(x, nTemp);
    }
    private double getPow(double x, long n) {
        if (n == 0) return 1;
        double res = getPow(x, n >> 1);
        res *= res;
        if ((n & 1) != 0) res *= x;
        return res;
    }
}
```