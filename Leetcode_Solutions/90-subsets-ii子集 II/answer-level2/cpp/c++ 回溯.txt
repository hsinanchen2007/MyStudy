### 解题思路
1. 先将nums数组排序
2. 排序后处理逻辑同题目： 78. 子集， 有略微区别
3. 当选择某个数的时候，处理方式和题目78相同；当不选择某个数的时候，将后续相等的数字一并跳过。
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp(nums.size());
        subsetsWithDup(nums, tmp, 0, 0);
        return result;
    }

    void subsetsWithDup(vector<int>& nums, vector<int>& tmp, int pos, int t_pos) {
        if (pos >= nums.size()) {
            result.emplace_back(vector<int>(tmp.begin(), tmp.begin() + t_pos));
            return;
        }
        tmp[t_pos] = nums[pos];
        subsetsWithDup(nums, tmp, pos+1, t_pos+1);     // 选择当前数
        while (pos+1 < nums.size() && nums[pos] == nums[pos+1]) pos ++;   // 不选择当前数时，后续相等的数也要跳过
        subsetsWithDup(nums, tmp, pos+1, t_pos);
    }
};
```