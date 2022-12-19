### 解题思路
二分 
满足二分的必须要具备二段性

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1)return x;
        long long l = 0;
        long long r = x;
        while(l < r){
            long long mid = (l+r+1)>>1;
            if(mid*mid <= x)l = mid;
            else r = mid - 1;
        }  
        return r;
    }
};
```