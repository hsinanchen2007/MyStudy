```java
class Solution {
    public double myPow(double x, int n) {
        boolean flag = n < 0;
        n = Math.abs(n);
        double result = 1;
        while (n != 0) {
            if ((n & 0x1) != 0)
                result *= x;
            x = x * x;
            n >>>= 1;
        }
        if (flag)
            result = 1 / result;
        return result;
    }
}
```

