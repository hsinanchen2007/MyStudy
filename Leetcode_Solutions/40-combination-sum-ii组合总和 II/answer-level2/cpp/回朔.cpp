### 解题思路
核心思路对比39题，组合总数，这里有个核心思想有2点。
1.不能选取相同的索引重复使用，所以递归时候 需要i+1
2.同一层中不能包含相同的元素，去重。

### 代码

```cpp
class Solution {
public:
    vector<int> path;
    vector<int> candidates;
    vector<vector<int>>  res;
    void dfs(int cur,int target)
    {
        if(target == 0) res.push_back(path);
        for(int i=cur;i<candidates.size();i++)
        {
            if(candidates[i] > target) break;
            //2.同一层中不能包含相同的元素，去重。
            if(i>cur && candidates[i-1] == candidates[i])
                continue;
            path.push_back(candidates[i]);
            //1.不能选取相同的索引重复使用，所以递归时候 需要i+1
            dfs(i+1,target-candidates[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->candidates = candidates;
        dfs(0,target);
        return res;
    }
};
```