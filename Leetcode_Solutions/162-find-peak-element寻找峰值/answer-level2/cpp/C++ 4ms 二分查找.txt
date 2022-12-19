### 解题思路
线性扫描最容易, 但是题目要求二分查找
查找峰值, 所以判断中点的梯度就能直接缩小搜索空间(梯度上升...)

### 代码

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int length = nums.size();
        int left = 0, right = length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[max(mid - 1, 0)] <= nums[mid] and nums[mid] >= nums[min(mid + 1, length - 1)]) 
                return mid;
            else if (mid > 0 and nums[mid - 1] > nums[mid])
                right = mid;
            else if (mid < length and nums[mid + 1] > nums[mid])
                left = mid + 1;
        }
        return left;
    }
};
```