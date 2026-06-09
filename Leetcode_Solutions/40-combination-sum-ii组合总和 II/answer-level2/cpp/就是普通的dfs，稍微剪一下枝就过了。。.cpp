### 解题思路
if(accumulate(temp.begin(),temp.end(),0) > target)
{
    return ;
}
这步减枝是精髓。。
### 代码

```cpp
class Solution {
    vector<vector<int> > result;
    vector<int> temp;
    void dfs(vector<int>& candidates,int i,int target)
    {
        if(accumulate(temp.begin(),temp.end(),0) == target)
        {
            result.push_back(temp);
            return ;
        }
        if(i == candidates.size()) return;
        
        if(accumulate(temp.begin(),temp.end(),0) > target)
        {
            return ;
        }

        temp.push_back(candidates[i]);
        dfs(candidates,i+1,target);
        temp.pop_back();
        dfs(candidates,i+1,target);
        return;
    }
        public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
        {
            sort(candidates.begin(),candidates.end());
            dfs(candidates,0,target);
            sort(result.begin(),result.end());
            result.erase(unique(result.begin(),result.end()),result.end());
            return result;
        }
};
```