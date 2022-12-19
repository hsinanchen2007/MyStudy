### 解题思路
符合题意的任何数的平方根一定 ≤ 这个数的二分之一加一（以1 为例）

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        for(long long  i=0;i<=x/2+1;++i){
             if((i*i <= x) && ((i+1)*(i+1)>x)){
                 return i;
             }
                
        }
        return -1;
    }
};
``````
转载自精品题解第一个
class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0

        left = 1
        right = x // 2

        while left < right:
            # 注意：这里一定取右中位数，如果取左中位数，代码可能会进入死循环
            # mid = left + (right - left + 1) // 2
            mid = (left + right + 1) >> 1
            square = mid * mid

            if square > x:
                right = mid - 1
            else:
                left = mid
        # 因为一定存在，因此无需后处理
        return left


```
