# 代码
```java []
class Solution {
    public double myPow(double x, int n) {
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        //double current_product = x;
        for (int i = 31; i >= 0; i--) {
            if(((1<<i)&N)!=0) ans=ans*ans*x;
            else ans=ans*ans;
        }
        return ans;
    }
}
```
