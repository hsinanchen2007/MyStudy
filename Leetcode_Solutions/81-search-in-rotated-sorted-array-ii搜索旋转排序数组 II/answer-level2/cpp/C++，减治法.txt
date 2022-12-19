### 代码

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;   // 特判
        
        int left = 0, mid, right = nums.size() - 1;

        while(left < right) {
            mid = left + (right - left) / 2;

            // [mid, right] 有序
            if(nums[mid] < nums[right]) {
                if(nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid;
            }
            // [left, mid] 有序
            else if(nums[mid] > nums[right]) {
                if(target <= nums[mid] && nums[left] <= target) right = mid;
                else left = mid + 1;
            }
            // [mid, right] 内左右边界元素相等，此时判断边界值是否等于 target，如不等于则收缩右边界
            else {
                if(nums[right] == target) return true;
                right--;
            }
        }

        return nums[left] == target;
    }
};
```