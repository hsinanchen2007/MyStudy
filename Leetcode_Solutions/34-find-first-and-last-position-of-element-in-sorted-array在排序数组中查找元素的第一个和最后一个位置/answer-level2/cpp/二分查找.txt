### 解题思路

先用二分查找到一个符合要求的值，再二边找到左右边界

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1,-1};
        int left = 0;
        int right = nums.size();
        int middle = 0;
        if (nums.size() <= 0) {
            return res;
        }
        // 先用二分查找到一个符合要求的值，再二边找到左右边界
        while (left < right) {
            middle = left + ((right - left) >> 1);
            if (nums[middle] == target) {
                res.clear();
                left = middle;
                while (left >= 0 && target == nums[left]) {
                    left--;
                }
                res.push_back(left + 1);
                right = middle;
                while (right < nums.size() && target == nums[right]) {
                    right++;
                }
                res.push_back(right - 1);
                break;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }
        return res;
    }
};
```