### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto begin =lower_bound(nums.begin(),nums.end(),target);
        auto end = upper_bound(nums.begin(),nums.end(),target);
        if (begin==end)return{-1,-1};
        return {(int)(begin-nums.begin()),(int)(end-nums.begin()-1)};
    }
};
```