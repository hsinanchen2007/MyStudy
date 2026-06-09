### 解题思路
参考题解中最高赞的回溯+剪枝

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(),candidates.end() );
        vector<vector<int> > vv;
        DFS(vv,candidates,target,{} );
        return vv;
    }

    void DFS(vector<vector<int>>& vv,vector<int> candidates, int target,vector<int> path)
    {
        for(int i = 0; i < candidates.size(); i++)
        {
            int tmp = target - candidates.at(i);
            if( tmp == 0)
            {
                path.push_back(candidates.at(i) );
                vv.push_back(path);
            }
            else if(tmp > 0)
            {
                path.push_back(candidates.at(i) );
                vector<int> candidate(candidates.begin(),candidates.begin()+i+1);
                DFS(vv,candidate,tmp,path);
                path.pop_back();
            }
        }
        return ;
    }
};
```