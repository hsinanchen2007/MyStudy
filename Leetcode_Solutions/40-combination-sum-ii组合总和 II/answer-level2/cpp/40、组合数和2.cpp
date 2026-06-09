```
#include <algorithm>

class Solution {
public:
    void dfs(int i, vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &chosen) 
    {
        if (target == 0) {
            res.push_back(chosen);
        }
        if (i >= candidates.size() || candidates[i] > target) return;
        dfs(i + 1, candidates, target, res, chosen);
        chosen.push_back(candidates[i]);
        dfs(i + 1, candidates, target - candidates[i], res, chosen);
        chosen.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res, unq;
        vector<int> chosen;
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target, res, chosen);
        map<vector<int>, int> m;
        for (auto i: res) {
            if (!m.count(i)) {
                unq.push_back(i);
                m[i]++;
            }
        }
        return unq;
    }
};
```
