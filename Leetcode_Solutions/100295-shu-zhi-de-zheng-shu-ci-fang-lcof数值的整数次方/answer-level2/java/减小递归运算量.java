### 解题思路


### 代码

```java
class Solution {
    public double myPow(double x, int num) {
        long n = (long)num;
        if (x == 1 || n == 0)
            return 1.0;
        if (n < 0){
            x = 1 / x;
            n = -n;
        }
        return pow(x, n);
    }

    public double pow(double x, long n){
        if (n == 1)
            return x;
        if (n % 2 != 0)
            return pow(x, n - 1) * x;
        return pow(x * x, n / 2);
    }
} 
```