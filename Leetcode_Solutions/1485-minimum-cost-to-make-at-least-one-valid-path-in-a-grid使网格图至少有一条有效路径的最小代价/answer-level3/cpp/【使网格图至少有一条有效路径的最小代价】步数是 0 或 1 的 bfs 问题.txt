### 执行时间
![图片.png](https://pic.leetcode-cn.com/7c3fbc95095c80b5bd90d11abbbb0ff48b4e9fb80801d32831f314015dce2a4f-%E5%9B%BE%E7%89%87.png)


### 思路
1. 使用 bfs ，找到最短路径
2. 有箭头的方向相当于步数 +0
3. 其他方向相当于步数 +1
4. 将 +0 的格子加入到本次队列
5. 将 +1 的格子加入到下次队列

### 答题
```C++
int minCost(vector<vector<int>>& grid)
{
    vector<vector<int>> dd = { {}, {0, 1}, {0, -1}, {1, 0}, {-1, 0} };  // 方向数组
    vector<vector<int>> vi(grid.size(), vector<int>(grid[0].size(), INT_MAX));  // 使用步数作为 visited 标准
    queue<vector<int>> cq;  // 本次队列 curr queue
    queue<vector<int>> nq;  // 下次队列 next queue
    int ans = 0;
    cq.push({ 0, 0 });
    vi[0][0] = 0;

    while (!cq.empty() || !nq.empty())
    {
        while (!cq.empty())
        {
            auto q = cq.front();
            cq.pop();
            int x = q[0];
            int y = q[1];
            if (vi[x][y] < ans) continue;
            if (x == grid.size() - 1 && y == grid[0].size() - 1) return ans;

            for (int i = 1; i < dd.size(); i++)
            {
                int dx = x + dd[i][0];
                int dy = y + dd[i][1];
                if ((dx < 0 || dx >= grid.size()) || (dy < 0 || dy >= grid[0].size())) continue;
                if (vi[dx][dy] <= ans) continue;

                // 将箭头所指格子加入当前队列，其他加入下次队列
                auto& sq = (i == grid[x][y]) ? cq : nq;
                sq.push({ dx, dy });
                vi[dx][dy] = (i == grid[x][y]) ? ans : ans + 1;
            }
        }
        swap(cq, nq);
        ans++;
    }
    return ans;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

