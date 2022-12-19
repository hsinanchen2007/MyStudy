### 执行时间
![图片.png](https://pic.leetcode-cn.com/9e14247451e2453fbb594cc4ead3118c3cbb8eeb1f3cc1b7cbcae5021837a8d0-%E5%9B%BE%E7%89%87.png)

### 思路
1. 回溯
2. 选和不选

### 答题
```C++ []
void dfs(int k, int sum, int idx, vector<int>& cur, vector<vector<int>>& ans)
{
    if (k == 0 && sum == 0)
    {
        //sort(cur.begin(), cur.end());
        ans.push_back(cur);
        return;
    }
    if (k == 0 || sum == 0) return;
        
    if (idx < 0) return;
    if (sum >= idx)
    {
        cur.push_back(idx);
        dfs(k - 1, sum - idx, idx - 1, cur, ans);
        cur.pop_back();
    }

    dfs(k, sum, idx - 1, cur, ans);
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> ans;
    vector<int> cur;
    dfs(k, n, 9, cur, ans);
    return ans;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

