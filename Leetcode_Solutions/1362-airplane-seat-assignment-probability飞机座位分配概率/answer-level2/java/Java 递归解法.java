```java
class Solution {
    public double nthPersonGetsNthSeat(int n) {
        if (n == 1) return 1d;
        return 1d / n + (n - 2d) / n * nthPersonGetsNthSeat(n - 1);
    }
}
```