### 解题思路
深搜 加 剪枝

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        generate(res, tmp, candidates, target, 0);

        return res;
    }

    void generate(vector<vector<int>>& res, vector<int> tmp, vector<int>& candidates, int target, int start) {
        int sum = accumulate(tmp.begin(), tmp.end(), 0);
        if (sum == target) {
            res.push_back(tmp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target - sum) {
                return;
            }
            tmp.push_back(candidates[i]);
            generate(res, tmp, candidates, target, i);
            tmp.pop_back();
        }
    }
};
```