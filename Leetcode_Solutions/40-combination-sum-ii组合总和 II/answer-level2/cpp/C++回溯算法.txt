### 解题思路
在前面一道题基础上改的。
注意一下去重问题即可。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    int t=0;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int u=0;
        for(;u<candidates.size();u++){
            if(candidates[u]>target)
            break;
        }
        candidates.erase(candidates.begin()+u,candidates.end());
        for(int i=0;i<candidates.size();i++){
            t=0;
            tmp.clear();
            dfs(i,candidates,target);
        }
        return res;
    }
    void dfs(int i,vector<int>& candidates,int target){
        t+=candidates[i];
        tmp.push_back(candidates[i]);
        if(t==target&&find(res.begin(),res.end(),tmp)==res.end())
        {res.push_back(tmp);
        return;}
        if(t+candidates[i]>target)
        return;
        for(int j=i+1;j<candidates.size();j++){
            dfs(j,candidates,target);
            tmp.pop_back();
            t-=candidates[j];
        }
    }
};
```