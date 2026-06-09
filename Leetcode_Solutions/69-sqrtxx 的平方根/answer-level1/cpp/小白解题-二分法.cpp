典型的二分解法 关键是想出边界条件
```
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 ||x == 1)
        {
            return x;
        }
        int left = 0;
        int right = x;
        while(left < right)
        {
            long long mid = left + (right-left)/2;
            if(mid == left)
            {
                return left;
            }
            if(mid * mid > x) //其他解题方法：mid > x / mid 赞一个
            {
                right = mid;
            }
            else if(mid * mid < x)
            {
                left = mid;
            }
            else 
            {
                return mid;
            }
        }
        return left;
    }
};
```
