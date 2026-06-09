### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double myPow(double x, int n) {
        if (n == Integer.MIN_VALUE) {
            return myPow(x, -1) * myPow(x, -Integer.MAX_VALUE);
        }
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 1 / myPow(x, -n);
        }
        int half = n / 2;
        double res = myPow(x, half);
        if ((n & 1) == 1) {
            return res * res * x;
        } else {
            return res * res;
        }
    }
}
```