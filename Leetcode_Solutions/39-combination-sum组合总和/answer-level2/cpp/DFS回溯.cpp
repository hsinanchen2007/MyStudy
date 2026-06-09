### 解题思路
使用DFS回溯算法，只需要保证下一个值不小于当前值则可以排除重复解。

### 代码

```cpp
class Solution {
public:
        vector<vector<int>> combinations;
        vector<int> combination;
        int n;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        for(int i = 0; i < candidates.size(); i++){  //这边其实可以省略放进dfs中
            combination.clear();
            dfs(0, i, target, candidates);
        }
        return combinations;
    }

    void dfs(int sum, int pre,int target, vector<int>& candidates){ 
        sum += candidates[pre];
        if(sum < target) {
            combination.push_back(candidates[pre]);
            for(int i = pre; i < candidates.size();i++){ //保证下一个值不小于当前值
                dfs(sum, i, target, candidates);
            }
            combination.pop_back();
        }
        else if(sum == target) {
            combination.push_back(candidates[pre]);
            combinations.push_back(combination);
            combination.pop_back();
        }
        return;
    }
};
```