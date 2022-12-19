### 解题思路

无重复元素的数组相当于一颗树：数组中各个值下面挂数组中的各个值直到永远（如果不给定深度的话）
![image.png](https://pic.leetcode-cn.com/3a48ccb35837f5bbf0ba97f0c75a4bf15689da099336c653e858cdb248ce62df-image.png)

那么转换到题目上来，树的深度就是递归结束的条件：
1，目标值一直减去各枝上的值小于0
2，目标值一直减去各枝上的值等于0

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tempRes;
        dfs(res, tempRes, candidates, 0, target);
        return res;
    }

    void dfs(vector<vector<int>>& res, vector<int> tempRes, vector<int>& candidates, int startIndex, int target) {
        // printf("startIndex:%d, target=%d, tempRes.size():%d\n", startIndex, target, tempRes.size());
        // if (target < 0) {
        //     tempRes.pop_back();
        //     return;
        // }
        if (target == 0) {
            res.push_back(tempRes);
        }
        // 数组映射成树，使用for循环即可
        // i不从0开始的作用是剪枝，前面一轮深度已经计算过的不需要重复计算了
        for (int i = startIndex; i < candidates.size(); ++i) {            
            if (target - candidates[i] >= 0) {
                // 大于等于0的枝才计算
                tempRes.push_back(candidates[i]);
                dfs(res, tempRes, candidates, i, target - candidates[i]);
                tempRes.pop_back();
            }            
        }
    }
};
```