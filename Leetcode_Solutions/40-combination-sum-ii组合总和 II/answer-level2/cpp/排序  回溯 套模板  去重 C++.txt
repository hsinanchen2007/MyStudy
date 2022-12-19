### 解题思路
1. 选当前值
2. dfs(t + 1) 
3. 不选当前值，走到这里说明刚才第2步的继续递归试探行不通，故不选
- // 已经选过的，不要再试了，去重 // 小剪枝
### 代码

```cpp
class Solution {
public:
    // 回溯 套模板
    // 1) 选当前值 2） dfs(t + 1) 3) 不选当前值
    vector<vector<int>> res;
    vector<int> tmp;

    void dfs(int t, vector<int>& can, int tar)
    {
        if(tar == 0)
        {
            res.push_back(tmp);
            return ;
        }
        for(int i = t; i < can.size(); i++)
        {
            if(can[i] > tar) break; // 大剪枝 当前值都比目标值大了，没必要再试探了，因为已经先排好序了，后面的会更大
            if(i > t && can[i] == can[i - 1]) continue; // 已经选过的，不要再试了，去重 // 小剪枝
            tmp.push_back(can[i]);
            dfs(i + 1, can, tar - can[i]);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target);
        return res;
    }

};
```