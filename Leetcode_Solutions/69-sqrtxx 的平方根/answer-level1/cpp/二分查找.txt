### 解题思路
用除法代替平方，防止溢出

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        int left = 1, right = x / 2, mid, rt = -1;
        while(left <= right){
            mid = left + ((right - left) >> 1);
            if(x / mid == mid || (x / mid > mid && x / (mid+1) < (mid+1))){
                rt = mid;
                break;
            }
            else if(x / mid > mid) left = mid + 1;
            else if(x / mid < mid) right = mid - 1;
        }
        return rt;
    }
};
```