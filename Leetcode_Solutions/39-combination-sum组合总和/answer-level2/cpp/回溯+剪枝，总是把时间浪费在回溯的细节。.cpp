### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res = {};
        if (candidates.empty()) {
            return res;
        }
        sort(candidates.begin(),candidates.end());
        int sum = 0;
        int pos = 0;
        vector<int> combination  ={};
        DFS(candidates, pos, target,sum, combination, res);
        return res;
    }

    void DFS(vector<int>& candidates, int pos, int target, int sum, vector<int> combination, vector<vector<int>> &res)
    {
        if (sum > target ){
            return;
        }
        if (sum == target) {
            res.emplace_back(combination);
            return;
        }
        for(int i = pos; i < candidates.size(); i++){
            if (candidates[i] > target){
                return;
            }
// Achtung! Die Zurückverfolgung in der for-Schleif muss manual machen.
            combination.emplace_back(candidates[i]);
            DFS(candidates, i, target, sum+candidates[i], combination, res);
            combination.pop_back();
        }

    }
};
```