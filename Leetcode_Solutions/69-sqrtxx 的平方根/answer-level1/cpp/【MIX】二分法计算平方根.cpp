### 解题思路
二分法

### 代码

```c++ []
class Solution {
public:
    int mySqrt(int x) {
        // 二分法
        long l=1;
        long r=x;
        while(l<r){
            long mid = l+(r-l)/2;
            if(mid*mid==(long)x) return (int)mid;
            else if(mid*mid<(long)x) l=mid+1;
            else r=mid;
        }
        l*l>x ? --l: l;
        return l; 
    }
};
```

**FOLLOW UP**
对浮点数计算$sqrt(x)$
```c++ []
// Follow UP: sqrt(x) II
class Solution {
    public double mySqrt(double x) {
        // 浮点数二分法
        double l = 0;
        double r = Math.max(x, 1.0);
        double EPS = 1e-12;

        while(l+EPS<r){
            double mid= l+(r-l)/2;
            if(mid*mid < x) l = mid;
            else r = mid;
        }
        return l;
    }
}
```