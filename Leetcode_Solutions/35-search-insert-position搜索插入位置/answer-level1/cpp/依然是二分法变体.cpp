### 解题思路
二分法变体 ，接上就是多一个判断是否在两侧

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            if (target < nums[left])
                return left;
            if (target > nums[right])
                return right + 1;
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                return mid;
        }

        return left;
    }
};
```