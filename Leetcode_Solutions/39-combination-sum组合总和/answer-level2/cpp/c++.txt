### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        findcom(candidates, 0, target);
        return res;
    }
    void findcom(vector<int>& candidates, int now, int target)
    {
        if (target == 0)//说明已经找到一种组合
        {
            res.push_back(path);
            return;
        }
        if (target < 0)//说明在从数组中选择一个元素加入后，超出范围
        {
            return;
        }
        if(now==candidates.size())//说明可选元素已经全部选完
        {
            return;
        }
        path.push_back(candidates[now]);//将当前数组位置元素加入（在递归中可以重复执行，说明每个元素可以重复）
        findcom(candidates, now, target - candidates[now]);//加入后需要找累加为target-candidates【now】的子问题
        path.pop_back();

        findcom(candidates, now + 1, target);//选择数组中下一个元素加入。
    }
};
```