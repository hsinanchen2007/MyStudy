## 思路
直接调用nth_element将排序后指定位置的值排出来
## 代码
```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + (k - 1), nums.end(), greater<int>());
        return nums[k - 1];
    }
};
```