有空补题解，先贴代码。

大家先做 [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/xian-yong-er-fen-fa-zhao-fen-ge-dian-zai-er-fen-ch)，先把没有重复的搞定，从答案上看与本题只差一个 if 条件。



```cpp
bool search(vector<int>& nums, int target) {
    if (nums.empty()) return false;
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo >> 1);
        if (nums[mid] == nums[hi]) {
            --hi; // 去重。
        } else if (target == nums[mid]
            || (nums[mid] >= nums[lo] && nums[lo] <= target && target < nums[mid])
            || (nums[mid] < nums[lo] && (target < nums[mid] || target >= nums[lo]))) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return nums[lo] == target;
}
```
