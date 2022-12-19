### 执行时间
![图片.png](https://pic.leetcode-cn.com/0636157975bcb2b55c54dc113b5a83e8379217ddafa503d1ebfd523f5cf9c1f2-%E5%9B%BE%E7%89%87.png)

### 思路
1. 回溯

2. 因为数组 `candidates` 是无重复元素的，所以组合的时候对每个元素在同一位置处理 0 - n 个，即可避免答案重复
> 比如 [1,2,3] ，只在第一层递归中，选择 1 的个数。可以选择 1,2... 个
> 进入下一层循环后，我们不再回头选择添加 1 ，而是向后选择 2 的个数
> 这样就可保证不出现 [1,1,2,3,1] 和 [1,1,1,2,3] 这样重复的问题

3. 回溯的时候，先每次递增 1 个，再最后一口气减去 k 个，可以优化一些回溯操作

4. 元素在数组中的顺序是没影响的，无需对 `candidates` 排序

### 答题
```C++
void dfs(vector<int>& candidates, int target, int idx, vector<int>& cur, vector<vector<int>>& ans)
{
    if (target == 0)
    {
        ans.push_back(cur);
        return;
    }
    if (idx >= candidates.size()) return;

    dfs(candidates, target, idx + 1, cur, ans); // k == 0
    for (int k = 1; k <= target / candidates[idx]; k++)
    {
        cur.push_back(candidates[idx]);
        dfs(candidates, target - k * candidates[idx], idx + 1, cur, ans);
    }
    for (int k = 1; k <= target / candidates[idx]; k++)
    {
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> cur;
    dfs(candidates, target, 0, cur, ans);
    return ans;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

