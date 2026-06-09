首先来查找起始位置的 target，就是在数组中查找第一个大于等于 target 的位置，当返回的位置越界，或者该位置上的值不等于 target 时，表示数组中没有 target，直接返回 {-1, -1} 即可。
若查找到了 target 值，则再查找第一个大于 target 的位置，然后把返回的位置减1，就是 target 的最后一个位置，即便是返回的值越界了，减1后也不会越界
```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> res(2, -1);
        int left = 0, right = nums.size();

        // 查找左边界，使用right定位
        // 如果target存在，则会定位到target左边界
        // 若果target不存在，且大于数组中所有值，则会定位到数组尾部
        // 若果target不存在, 且小于数组中某值，则会定位到第一个小于target的数据位置    
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        
        // 左边界特殊处理
        // 没找到target有两种情形
        if (right == nums.size() || nums[right] != target)
            return res;
        res[0] = right;
        
        // 查找右边界，使用right定位
        // 如果数组中有比target数值，定位到比target大的第一个位置，否则定位数组尾部之后
        right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        res[1] = right - 1;
        return res;
    }
};
```
