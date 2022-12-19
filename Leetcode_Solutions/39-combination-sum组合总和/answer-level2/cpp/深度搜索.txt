### 解题思路
对数组排序后深度搜索。
每次深度搜索都只搜索比当前值大于或等于的值。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, int target, vector<int>& cur, int index)
    //候选数，目标，已选数下标，搜索到哪个候选数
    {
        if (target == 0)//已选的以经组成目标值
        {
            vector<int> res1;
            for (int i = 0; i < cur.size(); i++)
            {
                res1.push_back(candidates[cur[i]]);
            }
            res.push_back(res1);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            int a = target - candidates[i];
            if (a >= 0)
            {
                cur.push_back(i);
                dfs(candidates, a, cur, i);
                cur.pop_back();
            }
            else
            {
                break;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());//先排序
        dfs(candidates, target, cur, 0);
        return res;
    }
};
```