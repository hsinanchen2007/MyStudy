### 解题思路
由于非降数组允许有重复元素，当 nums[low] == nums[mid] 时不一定为 low 与 high 重合的情况，targe 可能在 [low, mid-1] 或者 [mid+1, high]。此时可以 low++，也可以选择在 [left, high] 进行顺序查找。

### 代码

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target) return true;
            else if (nums[low] < nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            else if (nums[low] == nums[mid]) {
                low++;
            } else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
```