执行用时 :2 ms, 在所有Java提交中击败了99.21%的用户
内存消耗 :33.7 MB, 在所有Java提交中击败了73.49%的用户

```java
class Solution {
  public double myPow(double x, int n) {
    double base = x, result = 1;
    int m = Math.abs(n);
    while(m != 0) {
      if ((m & 1) != 0)
        result *= base;
      base *= base;
      m >>>= 1;
    }
    return n >= 0 ? result : 1 / result;
  }
}
```