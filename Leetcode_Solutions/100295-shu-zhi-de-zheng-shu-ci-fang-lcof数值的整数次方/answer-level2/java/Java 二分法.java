### 解题思路
二分法

### 代码

```java
class Solution {
    public double myPow(double x, int n) {
        if (x == 1) {
            return 1;
        }

        if (n == 0) {
            return x == 0 ? 0 : 1;
        } else if (n > 0) {
            return pow(x, n);
        } else {
            if (n == Integer.MIN_VALUE) {
                return 1.0 / (pow(x, - 1 - n) * x);
            }
            return 1.0 / pow(x, 0 - n);
        }
    }
    
    public double pow(double x, int n) {
        if (n == 1) {
            return x;
        }
        double y = pow(x, n/2);
        return y * y * (n % 2 == 1 ? x : 1);
    }
}
```