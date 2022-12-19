对二分查找稍微修改一下即可。
原二分查找关键点在于：
1. mid < target 则搜索 [left, mid -1];
2. mid > target 则搜索 [mid + 1, right];
3. 相等返回索引mid

现在主需要把第三点稍微修改一下即可： 加入min_ptr 和 max_ptr 分别记录最小、最大的相等索引
1. mid < target 则搜索 [left, mid -1];
2. mid > target 则搜索 [mid + 1, right];
3. **相等时继续搜索，并和 min_ptr、max_ptr 比较并记录；**

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() < 1 || nums.front() > target || nums.back() < target) return {-1, -1};
        int max_ptr = -1, min_ptr = -1;
        searchRange(nums, target, 0, nums.size() - 1, min_ptr, max_ptr);
        return {min_ptr, max_ptr};
    }
    void searchRange(vector<int>& nums, int& target, int l, int r, int& min_ptr, int& max_ptr)
    {
        if (l > r) return ;
        int mid = (l + r) / 2;
        if (nums[mid] < target) searchRange(nums, target, mid + 1, r, min_ptr, max_ptr);
        else if (nums[mid] > target) searchRange(nums, target, l, mid - 1, min_ptr, max_ptr);
        else
        {
            min_ptr = (min_ptr < mid) && (min_ptr != -1) ? min_ptr : mid;
            max_ptr = (max_ptr > mid) && (max_ptr != -1) ? max_ptr : mid;
            searchRange(nums, target, l, mid - 1, min_ptr, max_ptr);
            searchRange(nums, target, mid + 1, r, min_ptr, max_ptr);
        }
        return ;
    }
};
```


考虑一下两种情况：
1. 数组中全是target；
2. 超大规模数组，搜索到最后，必有在[left, right]范围内，绝大部分数都为target；

相等case中，递归的二分查找会有分支做无用功，所以需要对相等的情况做一个剪枝优化：

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() < 1 || nums.front() > target || nums.back() < target) return {-1, -1};
        int max_ptr = -1, min_ptr = -1;
        searchRange(nums, target, 0, nums.size() - 1, min_ptr, max_ptr);
        return {min_ptr, max_ptr};
    }
    void searchRange(vector<int>& nums, int& target, int l, int r, int& min_ptr, int& max_ptr)
    {
        if (l > r) return ;
        int mid = (l + r) / 2;
        if (nums[mid] < target) searchRange(nums, target, mid + 1, r, min_ptr, max_ptr);
        else if (nums[mid] > target) searchRange(nums, target, l, mid - 1, min_ptr, max_ptr);
        else
        {
            min_ptr = (min_ptr < mid) && (min_ptr != -1) ? min_ptr : mid;
            max_ptr = (max_ptr > mid) && (max_ptr != -1) ? max_ptr : mid;
            if (min_ptr > l || max_ptr < mid - 1) 
                searchRange(nums, target, l, mid - 1, min_ptr, max_ptr);
            if (min_ptr > mid + 1 || max_ptr < r) 
                searchRange(nums, target, mid + 1, r, min_ptr, max_ptr);
        }
        return ;
    }
};
```
