### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public double myPow(double x, int n) {
        if(n < 0) {
            return helper(1 / x, -n);
        } else {
            return helper(x, n);
        }
    }
    
    private double helper(double x, int n) {
        if(n == 0) {
            return 1;
        }
        
        if(n == 1) {
            return x;
        }
        
        double res = helper(x, n / 2);
        res *= res;
        
        if((n & 1) == 1) {
            res = x * res;
        }
        
        return res;
    }
}
```