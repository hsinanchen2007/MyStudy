# 二分查找思想 C++实现
我们知道，一个非负整数x的平方根s一定满足：s >= x/2。当然了，等号只在x = 2的处取得。

在区间[1, x/2]中，我们可以利用二分查找的思想进行求解。
下面是实现的代码：
```
class Solution{
public:
    int mySqrt(int x) {
        int start = 1;
        int end = x / 2;
        int mid;
        while (start <= end){
            mid = ( start + end ) / 2;
            if (mid == x / mid){
                /// mid * mid == x
                return mid;
            }else if (mid < x / mid && (mid + 1) > x/(mid + 1) ){
                /// mid * mid < x  && (mid + 1) * (mid + 1) > x
                return mid;
            }else if (mid > x / mid){
                end = mid - 1;
            }else {
                start = mid + 1;
            }
        }
        return x;/// x = 0, 1的时候,直接return x
    }
};
```
