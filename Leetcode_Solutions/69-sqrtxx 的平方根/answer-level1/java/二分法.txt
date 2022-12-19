### 解题思路
二分法

### 代码

```java
class Solution {
    public int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        long start = 0, end = x / 2;
        while (start + 1 < end) {
            long mid = start + (end - start) / 2;
            if (mid * mid < x) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (x < start * start) {
            return (int) (start - 1);
        } else if (x >= start * start && x < end * end) {
            return (int) (start);
        } else {
            return (int) (end);
        }
    }
}
```