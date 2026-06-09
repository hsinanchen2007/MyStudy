### 解题思路


### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int split = 0, right = nums.size() - 1;
        while(split < right)
        {
            int mid = split + (right - split) / 2;
            if(nums[mid] <= nums[right])
                right = mid;
            else
                split = mid + 1;
        }
        int left = 0;
        if(target > nums.back())
        {
            right = split - 1;
            left = 0;
        }
        else
        {
            right = nums.size() - 1;
            left = split;
        }
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        if(nums[left] == target)
            return left;
        else
            return -1;
    }
};
```