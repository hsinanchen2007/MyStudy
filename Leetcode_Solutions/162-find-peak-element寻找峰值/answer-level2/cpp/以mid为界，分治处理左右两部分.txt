### 解题思路
类似quickSort的分治处理方式
### 代码

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 1) {
            return 0;
        } else if (sz == 2) {
            return nums[0] > nums[1] ? 0 : 1;
        }

        int ret = findPeak(nums, 0, sz - 1);
        // 数组已序
        if (ret == -1) {
            ret = nums[0] > nums[sz - 1] ? 0 : sz - 1;
        }
        return ret;
    }

    int findPeak(vector<int>& nums, int start, int end) {
        if (start < 0 || start >= nums.size() || end < 0 || end >= nums.size()) {
            return -1;
        }

        if (end - start < 2) {
            return -1;
        }

        int mid = (end + start) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
            return mid;
        }
        int ret = findPeak(nums, start, mid);
        if (ret == -1) {
            ret = findPeak(nums, mid, end);
        }
        return ret;
    }
};
```