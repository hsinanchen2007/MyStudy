### 解题思路
日常DFS+剪枝，这里的剪枝其实就是去重，很重要，一定要有，要牢记这个套路！

### 代码

```cpp
class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>tep;
        dfs(candidates,target,tep,0);
        return ans;
    }
    inline void dfs(vector<int>candidates,int target,vector<int>tep,int tepindex)
    {
        if(target<0)return ;
        if(target==0)
        {
            ans.push_back(tep);
            return ;
        }
        for(int i=tepindex;i<candidates.size();i++)
        {
            target-=candidates[i];
            tep.push_back(candidates[i]);
            dfs(candidates,target,tep,i);
            target+=candidates[i];
            tep.pop_back();
        }
    }
};
```