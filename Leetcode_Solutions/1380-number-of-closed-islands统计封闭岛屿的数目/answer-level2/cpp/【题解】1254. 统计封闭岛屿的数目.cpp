**方法一：深度优先搜索**

我们可以从 `grid` 中的任意一个 `0` 开始，通过深度优先搜索，找出包含这个 `0` 的全 `0` 连通区域，即为一座岛屿。在搜索时，如果我们遇到一个边界上的 `0`，那就说明它不是封闭岛屿，不计入答案。

```C++ [sol1]
using PII = pair<int, int>;

class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
public:
    bool dfs(vector<vector<int>>& grid, int m, int n, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n) {
            return false;
        }
        if (grid[x][y] == 1) {
            return true;
        }
        grid[x][y] = 1;
        bool ret = true;
        for (int i = 0; i < 4; ++i) {
            ret &= dfs(grid, m, n, x + dirs[i][0], y + dirs[i][1]);
        }
        return ret;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    bool check = dfs(grid, m, n, i, j);
                    if (check) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};
```

**复杂度分析**

- 时间复杂度：$O(MN)$，其中 $M$ 和 $N$ 分别是数组 `grid` 的高和宽。

- 空间复杂度：$O(MN)$。

**方法二：广度优先搜索**

与方法一类似，我们也可以用广度优先搜索找出每一座岛屿。

```C++ [sol2]
using PII = pair<int, int>;

class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
public:
    bool bfs(vector<vector<int>>& grid, int m, int n, int sx, int sy) {
        queue<PII> q;
        q.emplace(sx, sy);
        grid[sx][sy] = 1;
        bool check = true;
        while (!q.empty()) {
            PII cur = q.front();
            q.pop();
            int curx = cur.first;
            int cury = cur.second;
            for (int i = 0; i < 4; ++i) {
                int nxtx = cur.first + dirs[i][0];
                int nxty = cur.second + dirs[i][1];
                if (nxtx < 0 || nxtx >= m || nxty < 0 || nxty >= n) {
                    check = false;
                }
                else if (grid[nxtx][nxty] == 0) {
                    q.emplace(nxtx, nxty);
                    grid[nxtx][nxty] = 1;
                }
            }
        }
        return check;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    bool check = bfs(grid, m, n, i, j);
                    if (check) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};
```

- 时间复杂度：$O(MN)$，其中 $M$ 和 $N$ 分别是数组 `grid` 的高和宽。

- 空间复杂度：$O(MN)$。