这一题和39题区别在于每个数字只能使用一次，在上一题的基础上，把递归的索引 “ +1 ” 即可。
但是这样会遇到一个问题，就是可能会出现重复的元素，例如：
[[1,1,6],[1,6,1],[6,1,1], ...] 这种情况。

可以采用multi_set去重，但是这里采用如下方法去重：
1. 先将candidate排序；
2. 循环时若candidate[i] == candidate[i-1]则跳过此循环；

原理就是，若candidate[i] == candidate[i-1]，则此次循环的答案，肯定被上一次循环所包含。
假如candidate = [1,1,1,6]，第一次循环 p = 0，指向第一个元素；那么 p = 1时的循环（组合元素为1,1,6）得到的答案一定被 p = 0 时的循环（组合元素为1,1,1,6）所包含。
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, target, res, cur, 0);
        return res;  
    }

    void combinationSum(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& cur, int p) 
    {
        if (target < 0) return ;
        else if (target == 0)
        {
            res.push_back(cur);
        }
        else
        {
            for (int i = p; i < candidates.size(); ++i)
            {
                if (i > p && candidates[i] == candidates[i - 1]) continue ;
                cur.push_back(candidates[i]);
                combinationSum(candidates, target - candidates[i], res, cur, i + 1);
                cur.pop_back();
            }
        }
        return ;
    }
};
```



