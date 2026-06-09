### 思路
1. 通过遍历，找到所有陆地
2. 判断是否全陆地或全海洋
3. 使用 bfs 
4. 直接修改原数组，对于距离为 1 的海洋格子，设置为 2 ；对于距离为 2 的海洋格子，设置为 3

### 答题
```C++ []
int maxDistance(vector<vector<int>>& grid)
{
    queue<pair<int, int>> que;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0) continue;
            que.push({ i,j });
        }
    }
    if (que.empty() || que.size() == grid.size() * grid[0].size()) return -1;

    int ans = 0;
    vector<vector<int>> dd = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    while (!que.empty())
    {
        auto q = que.front();
        que.pop();
        ans = grid[q.first][q.second];

        for (auto d : dd)
        {
            int dx = q.first + d[0];
            int dy = q.second + d[1];
            if (dx < 0 || dx >= grid.size()) continue;
            if (dy < 0 || dy >= grid[0].size()) continue;
            if (grid[dx][dy] != 0) continue;
            grid[dx][dy] = ans + 1;
            que.push({ dx, dy });
        }
    }
    return ans - 1;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

