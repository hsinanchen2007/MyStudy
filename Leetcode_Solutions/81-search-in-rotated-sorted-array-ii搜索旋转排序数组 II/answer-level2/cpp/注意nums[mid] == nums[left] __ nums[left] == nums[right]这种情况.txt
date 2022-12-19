
### 代码

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // std::cout << "mid: " << mid << ", left: " << left << ", right: " << right << std::endl;
            if (target == nums[mid] || target == nums[left] || target == nums[right]) return true;
            if (nums[left] == nums[right] || nums[left] == nums[mid]) {
                left++;
                continue;
            }
            if (nums[mid] > nums[left]) {
                if (target > nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target > nums[mid] && target < nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};
```