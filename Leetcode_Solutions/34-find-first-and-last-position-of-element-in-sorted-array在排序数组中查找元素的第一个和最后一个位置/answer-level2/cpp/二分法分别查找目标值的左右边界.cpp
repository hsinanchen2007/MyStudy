### 解题思路
**二分法**
使用二分法分别查找target的左侧边界和右侧边界，具体见代码。
时间复杂度：$O(logn)$
空间复杂度：$O(1)$
### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if(nums.size() < 1) return  res;
        int lo = 0;
        int hi = nums.size() -1;
        res[0] = findLeft(nums, target, lo, hi);
        res[1] = findRight(nums, target, lo, hi);
        return res;
    }
    //查找target左侧边界
    int findLeft(vector<int>& nums, int target, int lo, int hi){
        while(lo < hi)
        {
            int mid = (lo + hi) / 2;    //计算中间值，此中间值偏左
            if(target == nums[mid])
            {
                hi = mid;       //缩减查找区间
            }
            else if(target < nums[mid])
            {
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        if(nums[lo] == target)  //判断左边界是否存在
            return lo;
        else
            return -1;
    }
    //查找target右侧边界
    int findRight(vector<int>& nums, int target, int lo, int hi){
        while(lo < hi)
        {
            int mid = (lo + hi) / 2 + 1;        //计算中间值，此中间值偏右
            if(target == nums[mid])
            {
                lo = mid;
            }
            else if(target < nums[mid])
            {
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        if(nums[hi] == target)
            return hi;
        else
            return -1;
    }
};
```