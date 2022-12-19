### 解题思路
先查找旋转后的分界点，然后分别对两边进行二分查找

### 代码

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int mark = 0;
        for (int i = 0, sz = nums.size(); i < sz - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                mark = i + 1;
            }
        }

        return binarySearch(nums, 0, mark - 1, target) || binarySearch(nums, mark, nums.size() - 1, target);
    }
    bool binarySearch(vector<int>& nums, int start, int end, int target) {
        while (start <= end) {
            int mid = (start + end) / 2;
            if (target > nums[mid]) {
                start = mid + 1;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
```