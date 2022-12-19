迭代 - 内存炸了
暴力 - 超时
# 分治
注意Integer.MIN_VALUE：Java中的Integer.MIN_VALUE = -Integer.MIN_VALUE
### 递归
```
class Solution {
    public double myPow(double x, int n) {
        return n > 0 ? myPowHelper(x, n) : myPowHelper(1 / x, -(long)n);
    }
    private double myPowHelper(double x, long n) {
        if (n == 0) return 1;
        if (n == 1 || x == 1) return x;
        double result = myPowHelper(x, n / 2);
        return n % 2 == 0 ? result * result : result * result * x;
    }
}
```
时间复杂度: O(logn)
空间复杂度: O(h)
### 位运算
```
class Solution {

    public double myPow(double x, int n) {
        double result = 1;
        double bitVal = n < 0 ? 1 / x : x;
        // Integer.MIN_VALUE对于位操作而言无影响
        if (n < 0) n *= -1;
        while (n != 0) {
            if ((n & 1) == 1) result *= bitVal;
            bitVal *=  bitVal;
            n >>>= 1;
        }
        return result;
    }
}
```
时间复杂度: O(logn)
空间复杂度: O(1)


