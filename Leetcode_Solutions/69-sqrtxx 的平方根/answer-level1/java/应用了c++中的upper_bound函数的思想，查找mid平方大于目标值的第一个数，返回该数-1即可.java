### 解题思路


### 代码

```java
class Solution {
    public int mySqrt(int x) {
        //if (x <= 1) return x;
        long lo = 0;
        long hi = (long) x + 1;
        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            if (mid * mid > x) hi = mid;
            else lo = mid + 1;
        }
        return (int) lo - 1;
    }
   
}
```