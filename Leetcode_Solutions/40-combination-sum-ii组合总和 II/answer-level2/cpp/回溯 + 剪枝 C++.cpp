### 解题思路
回溯 + 剪枝

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        int sum = 0;
        int start = 0;
        vector<bool> used(candidates.size(), false);
        std::sort(candidates.begin(), candidates.end());
        traceback(res, tmp, candidates, target, sum, start, used);
        return res;
    }

    void traceback(vector<vector<int>>& res, vector<int>& tmp, vector<int>& candidates, int target, int sum, int start, vector<bool>& used) {
        if (target < sum) {
            return;
        }
        if (target == sum) {
            res.push_back(tmp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > 0 && candidates[i] == candidates[i-1] && !used[i-1]) {
                continue;
            }
            tmp.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            traceback(res, tmp, candidates, target, sum, i + 1, used);
            tmp.pop_back();
            sum -= candidates[i];
            used[i] = false;
        }
    }
};
```