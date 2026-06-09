### 解题思路
时间复杂度O（log2n）
空间复杂度O(1)

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //返回第一个大于等于target的迭代器
        auto start = lower_bound(nums.begin(), nums.end(), target);
        //返回第一个大于target的迭代器
        auto finsh = upper_bound(nums.begin(), nums.end(), target);
        //相等说明*start > target 且 *finsh > target，即target不在数组中
        if(start == finsh) return {-1,-1};
        return {start-nums.begin(), finsh-nums.begin()-1};
    }
};
```