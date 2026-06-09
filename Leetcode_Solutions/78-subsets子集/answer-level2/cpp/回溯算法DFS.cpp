### 解题思路
直接回溯既可。

### 代码

```cpp
class Solution {
public:
    set<vector<int>> vecResult;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> result;
        Dfs(nums, 0, result);
        vector<vector<int>> res(vecResult.begin(), vecResult.end());
        return res;
    }
    void Dfs(vector<int>& nums, int index, vector<int> result) {
        if (index >= nums.size()) {
            vecResult.insert(result);
            return;
        }
        Dfs(nums, index + 1, result);
        result.push_back(nums[index]);
        Dfs(nums, index + 1, result);
        return;
    }
};
```