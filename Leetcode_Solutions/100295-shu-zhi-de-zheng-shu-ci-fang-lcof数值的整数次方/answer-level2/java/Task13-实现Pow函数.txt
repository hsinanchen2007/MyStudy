### 解题思路
基本上就是将X^n -> X ^ 2 ^ n/2来计算。

### 代码

```java
class Solution {
    public double myPow(double x, int n) {
        // 只能使用递归方法
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        if (n == -1) {
            return 1 / x;
        }
        double half = myPow(x , n / 2);
        double res = myPow(x, n % 2);
        return half * half * res;

    }
}
```