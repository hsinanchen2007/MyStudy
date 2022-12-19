### 解题思路
二分法查询, 这么写思路很顺, 只用单独考虑收敛到右边界的情况。

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = (high-low) / 2 + low;
        while (low != high)
        {
            int midNum = nums[mid];
            if (midNum > target)
            {
                high = mid;
            }
            else if (midNum < target)
            {
                low = mid + 1;
            }else{
                return mid;
            }
            mid = (high-low) / 2 + low;
        }
        
        if(nums[low] < target)
            low ++;
        return low;
    }
};
```