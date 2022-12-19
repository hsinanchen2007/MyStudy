### 解题思路
基本的二分查找C++写法

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while (left<=right) {
            int mid = (left+right)/2;
            if (nums[mid]==target) {
                return mid;
            } else if (nums[mid]>target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};
```