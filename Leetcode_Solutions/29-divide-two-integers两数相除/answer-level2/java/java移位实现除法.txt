### 解题思路
此处撰写解题思路
注意这种边界情况的处理
        //防止溢出，这里先加上abs(divisor)
        if (dividend == Integer.MIN_VALUE) {
            dividend += divisor;
            //这里注意res += 1
            res += 1;
        }
每次循环
    1. 被除数 -= 2^n*除数 
    2. res += 2^n
### 代码

```java
class Solution {
    public int divide(int dividend, int divisor) {
        if (divisor == Integer.MIN_VALUE && dividend == Integer.MIN_VALUE) {
            return 1;
        }
        if (divisor == Integer.MIN_VALUE) {
            return 0;
        }
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        int res = 0;
        boolean neg = false;
        if (divisor < 0) {
            neg = !neg;
            divisor *= -1;
        }
        //防止溢出，这里先加上abs(divisor)
        if (dividend == Integer.MIN_VALUE) {
            dividend += divisor;
            //这里注意res += 1
            res += 1;
        }
        if (dividend < 0) {
            neg = !neg;
            dividend *= -1;
        }
        while (dividend >= divisor) {
            int r = 1;
            int x = divisor;
            //Integer.MAX_VALUE / 2 >= x 这个条件不能漏，防止Integer溢出
            while (dividend >= (x << 1) && Integer.MAX_VALUE / 2 >= x) {
                r <<= 1;
                x <<= 1;
            }
            res += r;
            dividend -= x;
        }
        return res * (neg ? -1 : 1);
    }
}
```