### 解题思路
二分查找变种

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) { 
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                //左边是递增的
                if (nums[left] <= nums[mid]) {
                    if (nums[left] > target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                } else {
                    right = mid - 1;
                }
            } else {
                if (nums[left] <= nums[mid]) {
                    left = mid + 1;
                } else {
                    if (nums[right] < target) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
};
```