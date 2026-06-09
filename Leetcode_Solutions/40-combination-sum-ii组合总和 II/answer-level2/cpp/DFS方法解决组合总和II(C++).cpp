### 解题思路
本题类似于"39题组合总和"，两者差别在于candidates中的每个数字在每个组合中只能使用一次或者使用无数次。在剪枝过程中，若遇到连续重复数字时，直接跳过。

### 代码

```cpp
class Solution {
public:
     vector<vector<int>> res;
    vector<int> vec;
    void dfs(vector<int>& candidates, int current, int last )
    {
        if(current == 0) 
        {
            res.push_back(vec);
            return;
        }
        if(current < 0) return;
        for(int i = last; i < candidates.size(); i++)
        {
            if(i > last && candidates[i - 1] == candidates[i]) continue;
            vec.push_back(candidates[i]);
            dfs(candidates,current - candidates[i], i + 1);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty()) return res;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target,0);
        return res;
    }
};
```