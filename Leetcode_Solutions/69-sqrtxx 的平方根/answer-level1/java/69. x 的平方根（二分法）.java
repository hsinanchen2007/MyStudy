### 解题思路

left 和 right 使用 long 类型，使用 int 类型时在 mid * mid 的时候如果 x = 2147483646，会产生越界问题

### 代码

```java
class Solution {
    public int mySqrt(int x) {
        long left = 1;
        long right = x;
        while (left <= right) {
            long mid = (left + right) / 2;
            if (mid * mid == x) {
                return (int) mid;
            } else if (mid * mid < x) {
                left = (int) mid + 1;
            } else {
                right = (int) mid - 1;
            }
        }
        return (int) right;
    }
}
```