### 解题思路
CASE1：nums[mid] == target
当nums[mid]恰好等于target时，返回mid值，即nums[mid] == target
CASE2：nums[low] < nums[mid]
nums[low] <= nums[mid]（0 - mid不包含旋转）且nums[low] <= target <= nums[mid] 时 high = mid - 1；
nums[mid] < nums[low]（0 - mid包含旋转），target <= nums[mid] < nums[low] 时high = mid - 1（target 在旋转位置到 mid 之间）
nums[mid] < nums[low]，nums[mid] < nums[low] <= target 时 high = mid - 1（target 在 0 到旋转位置之间）
即target >= nums[low] && target <= nums[mid]时，high = mid - 1
CASE3:nums[low] >= nums[mid]
类似CASE2情况，即target >= nums[mid + 1] && target <= nums[high]时，low = mid + 1


### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() < 1) return -1;
        int low = 0, high = nums.size() - 1;
        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            if(nums[low] < nums[mid])
            {
                if(target >= nums[low] && target <= nums[mid])
                {
                    high = mid - 1;
                } 
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if(target >= nums[mid + 1] && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        if(nums[low] == target) return low;
        return -1;
    }
};
```