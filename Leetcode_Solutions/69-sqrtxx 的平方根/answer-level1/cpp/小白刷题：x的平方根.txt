牛顿迭代法

求平方根公式：f(n+1)=(f(n)+x/f(n))/2

易得f(n)数列收敛，极限就是x的平方根

代码：
```
class Solution {
public:
    int mySqrt(int x) {
        double ans = 1.0;
        double temp = (ans + (double)x / ans) / 2.0;
        while (fabs(temp - ans) > 1e-8) {
            ans = temp;
            temp = (ans + (double)x / ans) / 2.0;
        }
        return (int)ans;
    }
};
```
