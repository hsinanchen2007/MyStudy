好坑啊。。。好多情况没考虑到啊

建议先看搜索旋转排序数组1  https://leetcode-cn.com/problems/search-in-rotated-sorted-array/，
套用解法的话，然后发现会被卡在`nums[lo] == nums[mid]`的情况上。暂时没想到好的解法，只能递归了。。

```
class Solution {
public:
    bool doSearch(vector<int>& nums, int target, int start, int end) {
        int lo = start, hi = end;
        while (lo != hi) {
            const int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[lo] < nums[mid]) {
                if (nums[lo] <= target && target < nums[mid])
                    hi = mid;
                else
                    lo = mid + 1;
            } else if (nums[lo] > nums[mid]) {
                if (nums[mid] < target && target <= nums[hi-1])
                    lo = mid + 1;
                else
                    hi = mid;
            } else {
                return doSearch(nums, target, lo, mid) || doSearch(nums, target, mid+1, end);
            }
        }
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        return doSearch(nums, target, 0, (int)nums.size());
    }
};
```