### 解题思路
根据精选题解思路，以target为根结点，对每一个分支做减法。直到减到0或者负数时，然后剪枝，即递归结束，开发回溯。其中减到0的时候添加到结果集res，即从0这一点到根结点走的路径，就是一个组合，把根结点到0所经过的路径，加入结果集。减的结果为负数，表示此路不通，不再继续。需要注意的是结果集会出现重复，解决办法是后面选取的数不能比前面选的数还要小，即 “更深层的边上的数值不能比它上层的边上的数值小”。

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
        for(int i = 0; i < candidates.size(); i++)
        {
            if(candidates[i] < last) continue; //剪枝操作
            vec.push_back(candidates[i]);
            dfs(candidates,current - candidates[i], candidates[i]);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty()) return res;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }
};
```