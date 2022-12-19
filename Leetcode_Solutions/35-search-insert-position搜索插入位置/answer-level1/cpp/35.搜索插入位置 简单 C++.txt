### 解题思路
二分查找的思路，整个过程与二分查找无二，关键在于找不到的处理，返回的是low位，则为应该插入的位置。
而为什么是low，不是high，这是观察得出0.0

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while(low <= high) {
            mid = (low + high) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
```