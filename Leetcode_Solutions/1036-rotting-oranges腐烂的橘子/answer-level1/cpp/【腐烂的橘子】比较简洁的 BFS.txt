### 思路
1. 第一件要做的事，是怎么找到周围的橘子
    * 如果一个橘子是腐烂的，那么它上下左右的橘子也会变腐烂
    * 对上下左右格子，可以使用方向数组，即保存 `[1,0]`, `[-1,0]`, `[0,1]`, `[0,-1]`
    * 然后就可以方便的通过循环，让原坐标对每个方向相加，就能得到所有新坐标

2. 怎么体现腐烂传播的速度
    * 注意到 `0` 代表空，`1` 代表新鲜，`2`代表腐烂
    * 可以把 `3` 代表第一天被 `2` 腐烂的， `4` 代表第二天由 `3` 腐烂的
    * 这样 `grid[i][j] - 2` 就是经过了多少天

3. 腐烂周围的橘子
    * 初始的时候我们先找到所有所有腐烂的橘子
    * 把它们加入到队列
    * 把队列中每个橘子依次取出来，对周围的新鲜橘子（ `grid[i][j] == 1` ）进行腐烂
    * 腐烂的值等于自己的值 + 1 ，就表示通过自己给它腐烂的
    * 记录天数就等于 `grid[newi][newj] - 2`
    * 把新腐烂的橘子加入到队列，让他等下去腐烂其他橘子

4. 对新鲜橘子计数
    * 每腐烂一个，就减少一个
    * 当队列为空时，表示所有能腐烂的橘子都腐烂完了
    * 此时计数如果还有剩，就说明还有新鲜的橘子，返回 -1
    * 否则返回天数

### 答题
```C++ []
int orangesRotting(vector<vector<int>>& grid)
{
    int cnt = 0;
    queue<vector<int>> que;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 2)
            {
                que.push({ i, j });
            }
            else if (grid[i][j] == 1)
            {
                cnt++;
            }
        }
    }

    int ans = 0;
    vector<vector<int>> dd = { {0,1},{0,-1},{1,0},{-1,0} };
    while (!que.empty())
    {
        auto q = que.front();
        que.pop();

        for (auto d : dd)
        {
            int dx = q[0] + d[0];
            int dy = q[1] + d[1];
            if (dx < 0 || dx >= grid.size()) continue;
            if (dy < 0 || dy >= grid[0].size()) continue;
            if (grid[dx][dy] != 1) continue;
            grid[dx][dy] = grid[q[0]][q[1]] + 1;
            cnt--;
            que.push({ dx, dy });
            ans = grid[dx][dy] - 2;
        }
    }
    return (cnt == 0) ? ans : -1;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

