### 思路
1. 和最普通的数岛屿个数的区别只是要求封闭
2. 只需要代入一个变量表示是否封闭

### 答题
```C++
void dfs(vector<vector<int>>& g, size_t x, size_t y, int &val)
{
    if (x >= g.size() || y >= g[0].size())
    {
        val = 0;
        return;
    }

    if (g[x][y] != 0) return;
    g[x][y] = -1;

    dfs(g, x + 1, y, val);
    dfs(g, x - 1, y, val);
    dfs(g, x, y + 1, val);
    dfs(g, x, y - 1, val);       
}
```
```C++
int closedIsland(vector<vector<int>>& grid)
{
    int ans = 0;
    for (size_t x = 0; x < grid.size(); x++)
    {
        for (size_t y = 0; y < grid[0].size(); y++)
        {
            if (grid[x][y] == 0)
            {
                int val = 1;
                dfs(grid, x, y, val);
                ans += val;
            }
        }
    }
    return ans;
}
```



### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

