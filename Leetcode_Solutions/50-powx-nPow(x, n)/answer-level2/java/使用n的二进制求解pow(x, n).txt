### 解题思路
因为`n`的取值范围为`[2^(-31), 2^31 -1]`，

当`n < 0`时其翻转变为正数避免溢出，可以将`n + 1`再进行翻转，同时将`ans`有1变成`1.0/x`
即：
```
if (n < 0) {
    x = 1 / x;
    n = -(n + 1);
    ans = x;
}
```
而后在使用n的二进制进行乘积求解。

注意：其中有个技巧：n为正数时，**求其一半**可以使用`n >> 1`，即n右移一位，而**余数**可以为`n & 1`

### 代码

```java
class Solution {
    public double myPow(double x, int n) {
        double ans = 1.0;
        if (n < 0) {
            x = 1 / x;
            n = -(n + 1);
            ans = x;
        }
        double current_product = x;
        for (int i = n; i > 0; i >>= 1) {
            if ((i & 1) == 1) {
                ans = ans * current_product;
            }
            current_product = current_product * current_product;
        }
        return ans;
    }
}
```