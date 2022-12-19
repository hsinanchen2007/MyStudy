### 解题思路
深度优先搜索，回溯，巧妙利用了swap
这个代码应该很精简了！

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(result, nums, 0);
        return result;
    }
    void dfs(vector<vector<int>> &result, vector<int> nums, int depth) {
        if(depth == nums.size() - 1)
            result.push_back(nums);
        for(int i = depth; i < nums.size(); i++) {
            swap(nums[depth], nums[i]);
            dfs(result, nums, depth + 1);
            swap(nums[depth], nums[i]);
        }
    }
};
```