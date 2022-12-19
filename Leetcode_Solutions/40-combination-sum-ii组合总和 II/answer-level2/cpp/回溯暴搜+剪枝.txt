### 解题思路
剪枝是这道题的精髓，函数参数加引用加速

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        DFS(0, candidates, 0, target, v);
        return vv;
    }
    void DFS(int start, vector<int> candidates, int sum, int target, vector<int> &v)
    {
        if(sum == target)
        {
            //if(find(vv.begin(), vv.end(), v) == vv.end())
                vv.push_back(v);
            return ;
        }
        for(int i = start ; i < candidates.size() && sum + candidates[i] <= target ; ++i)
        {
            if(i > start && candidates[i] == candidates[i - 1])
            continue;
            v.push_back(candidates[i]);
            DFS(i + 1, candidates, sum + candidates[i], target, v);
            v.pop_back();
        }
    }
private:
    vector<vector<int> > vv;
};
```