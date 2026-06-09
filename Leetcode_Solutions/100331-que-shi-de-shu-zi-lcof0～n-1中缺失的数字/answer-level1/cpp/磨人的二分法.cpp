### 解题思路
l,r, mid = (l+r)/2
普通情况有两种：
1. nums[mid] = mid
    说明顺序没有发生变化，那么缺失值一定在右边, l = mid+1
2. nums[mid] != mid
    说明顺序已经发生变化，说明缺失值一定在左边, r = mid
特殊情况：
1. 数组大小为n-1，最后一个值缺失，这样直接二分会导致越界（事先判断是否nums[n-1]==n-1，是就直接返回n）

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(!nums.size()) return 0;
        if(nums.size() == 1) return 1-nums[0];
        if(nums[nums.size()-1] == nums.size()-1) return nums.size();
        int n = nums.size();
        int l=0, r=n-1;
        while(l<r){
            int mid = (l+r)>>1; 
            if(mid == nums[mid]) l = mid+1;     //顺序没有乱，说明在右边
            else r=mid;                         //顺序乱了，说明在左边
        }
  //      if(nums[r] == r) return r+1;
        return r;
    }
};
```