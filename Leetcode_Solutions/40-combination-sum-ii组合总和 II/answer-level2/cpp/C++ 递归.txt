### 解题思路
此题与题目39一样，然后需要两句去重答案的操作，以及一个解中不包含已减去的当前值的改动。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int> > vv;
        sort(candidates.begin(),candidates.end() );
        DFS(vv,candidates,target,{} );
        return vv;
    }

    void DFS(vector<vector<int>>& vv,vector<int> candidates, int target,vector<int> path)
    {
        for(int i = candidates.size()-1; i >= 0; i--)
        {
            int tmp = target - candidates.at(i);
            if( tmp == 0)
            {
                if(i < candidates.size()-1 && candidates[i] == candidates[i+1] ) continue;  // 去重
                path.push_back(candidates.at(i) );
                vv.push_back(path);
                path.pop_back();
            }
            else if(tmp > 0)
            {
                if(i < candidates.size()-1 && candidates[i] == candidates[i+1] ) continue;  //去重
                path.push_back(candidates.at(i) );
                vector<int> candidate(candidates.begin(),candidates.begin()+i);  // 不能重复使用，传candidates.begin()+i,重复使用传+i+1
                DFS(vv,candidate,tmp,path);
                path.pop_back();
            }
        }
        return ;
    }
};
```