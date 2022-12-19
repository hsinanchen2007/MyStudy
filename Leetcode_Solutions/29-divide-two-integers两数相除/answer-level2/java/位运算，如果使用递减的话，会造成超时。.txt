使用位运算进行计算可防止超时。
通过将 除数一直乘以2 来逼近被除数，然后 被除数减去这个最大值，继续逼近。
由于对 除数右移 有溢出风险，所以选择将被除数左移。

注：对于位运算来说，左移一位相当于 乘以2，右移一位相当于 除以2。

```java
class Solution {
  public int divide(int dividend, int divisor) {
    if (dividend == Integer.MIN_VALUE && divisor == -1)
      return Integer.MAX_VALUE;
    // 用来判断符号是否相异
    Boolean flag = (dividend ^ divisor) >= 0;
    Long dividendLong = Math.abs((long)dividend);
    Long divisorLong = Math.abs((long)divisor);
    int result = 0;
    for (int i = 31; i >= 0; i--) {
      if ((dividendLong >> i) - divisorLong >= 0) {
        result += (1 << i);
        dividendLong -= (divisorLong << i);
      }
    }
    return flag ? result : -result;
  }
}
```