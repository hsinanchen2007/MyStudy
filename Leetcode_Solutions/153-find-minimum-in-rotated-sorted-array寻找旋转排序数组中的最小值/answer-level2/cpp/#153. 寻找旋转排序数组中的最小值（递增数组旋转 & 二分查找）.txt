### 解题思路
当 nums[low] <= nums[high], [low, high] 是递增的，返回 low。
如果 nums[low] <= nums[mid], [low, mid] 是递增的，最小值在 [mid+1, high]
如果 nums[low] >  nums[mid], [mid, high] 是递增的，此时 nums[mid] 可能是最小值，判断是不是，如果不是则最小值在 [low, mid-1]

### 代码
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            if (nums[low] <= nums[high]) return nums[low];
            int mid = low + ((high - low) >> 1);
            if (nums[low] <= nums[mid]) low = mid + 1;
            else if (nums[mid] < nums[mid-1]) return nums[mid];
            else high = mid - 1;
        }
        return -1;
    }
};
```