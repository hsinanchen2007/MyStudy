### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
        int res = find(nums, 0, nums.size() - 1);
        return res;
    }
    int find(vector<int>& nums, int start, int end)
    {
        if (start == end)
           return nums[start];
        if (start + 1 == end)
           if (nums[start] < nums [end])
              return nums[start];
           else
              return nums[end];
        int mid = (start + end) / 2;
        if ((mid + 1 <= end && mid - 1 < start)
            || (mid + 1 <= end && mid - 1>= start && nums[start] > nums[end] && nums[mid - 1] > nums[mid + 1]))
           return min(find(nums, mid + 1, end), nums[mid]);
        if ((mid + 1 > end && mid - 1 >= start)
        || (mid + 1 <= end && mid - 1>= start && nums[start] < nums[end] && nums[mid - 1] < nums[mid + 1]))
           return min(find(nums, start, mid - 1), nums[mid]);
        if (mid - 1 >= start && mid + 1 <= end)
           return min(min(find(nums, mid + 1, end), find(nums, start, mid - 1)), nums[mid]);
        return 0;
    }
};
```