## 思路 二分查找
使用C++自带的二分查找库
## 代码
```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto bounds = equal_range(nums.begin(), nums.end(), target);
        auto a = distance(nums.begin(), bounds.first);
        auto b = distance(nums.begin(), bounds.second);
        if (a < b) {
            return {a, b - 1};
        } else {
            return {-1, -1};
        }
    }
};
```