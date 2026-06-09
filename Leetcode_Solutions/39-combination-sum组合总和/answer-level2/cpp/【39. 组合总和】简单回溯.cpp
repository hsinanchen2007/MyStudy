### 思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        helper(candidates, target, 0, cur, res);
        return res;
    }

    void helper(vector<int> &candidates, int target, int i, vector<int> &cur, vector<vector<int>> &res) {
        if (target < 0) return;
        if (target == 0) {
            res.push_back(cur);
            return;
        } 
        for (int j = i; j < candidates.size(); ++j) {
            cur.push_back(candidates[j]);
            helper(candidates, target - candidates[j], j, cur, res);
            cur.pop_back();
        }
    }
};
```