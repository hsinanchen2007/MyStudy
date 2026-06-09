### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double myPow(double x, int n) {
        double res = 1;
        if (n == 0) return 1;
        if (n < 0) {
            x = 1 / x;  
            n = -n;  
        } 
        return count(x, n);
    }
    double count(double x, int n) {
        if (n == 0) return 1;
        double temp = count(x, n / 2);
        if (n % 2 == 0) {
            return temp * temp;
        } else {
            return temp  * temp * x;
        }
    }
}
```