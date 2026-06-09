### 思路
- 当数组大小为一时，返回0（题：你可以假设 nums[-1] = nums[n] = -∞。）
- 当数组大小为二时，对比返回较大值的索引
- 当数组大于二时，峰值可能出现在数组的中间某处或左右边界，因此注意条件
- 将范围往斜率上升的方向缩
```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        if(nums.size() == 1)    return 0;
        if(nums.size() == 2)    return nums[0] > nums[1] ? 0 : 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if((mid == 0 && nums[mid] > nums[mid + 1]) || (mid == nums.size() - 1 && nums[mid] > nums[mid - 1]) ||(mid != 0 && mid != nums.size()-1 && nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])) return mid;
            if(mid == 0 || nums[mid + 1] > nums[mid - 1])  l = mid + 1;
            else    r = mid - 1;
        }
        return -1;
    }
};
```
