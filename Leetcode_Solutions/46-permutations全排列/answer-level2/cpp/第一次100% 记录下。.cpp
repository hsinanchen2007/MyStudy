
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :9.3 MB, 在所有 C++ 提交中击败了57.55%的用户


### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void backTrack(vector<int>& nums, int index, vector<vector<int>>& table)
    {
        int len = nums.size();
        if (index == len) {
            table.push_back(nums);
            return;
        }
        for (int i = index; i < len; i++) {
            swap(nums[i], nums[index]);
            backTrack(nums, index + 1, table);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> table;
        backTrack(nums, 0, table);
        return table;
    }
};
```