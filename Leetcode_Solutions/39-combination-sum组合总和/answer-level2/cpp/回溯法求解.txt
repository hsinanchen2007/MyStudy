### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,target,0);
        return res;
    }
    void dfs(vector<int>& candidates,int target,int start){
        if(target < 0) return;
        if(target == 0){
            res.push_back(ans);
            return;
        }
        for(int i = start;i < candidates.size();i++){
            ans.push_back(candidates[i]);
            dfs(candidates,target - candidates[i],i);
            ans.pop_back();
        }
        return ;
    }
};
```