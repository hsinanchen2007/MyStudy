### 解题思路
二分查找最大的小于target的数的位置

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        if (nums[left] < target) return left + 1;
        return 0;
    }
};
```