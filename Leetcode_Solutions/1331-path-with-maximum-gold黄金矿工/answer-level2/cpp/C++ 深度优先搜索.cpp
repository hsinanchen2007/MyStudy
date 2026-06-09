# 思路
1，其实我们只需要对处于路径端点的点进行dfs即可，减少计算量
2，如果所有的点周围都至少有两个黄金矿，那说明整个图的金矿都连在一起，需要特殊处理一下

```C++ []
class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool canBeStartPoint(const vector<vector<int> >& grid, int r, int c, int R, int C) {
        int nei = 0;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (nr >=0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] > 0) {
                ++nei;
            }
        }
        return nei <= 1;
    }
    void dfs(const vector<vector<int> >& grid, int r, int c, int R, int C, vector<vector<int> >& visited, int gain, int& res) {
        visited[r][c] = 1;
        gain += grid[r][c];
        res = max(res, gain);
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];
            if (nr >=0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] > 0 && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                dfs(grid, nr, nc, R, C, visited, gain, res);
                visited[nr][nc] = 0;
            }
        }
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<int> > visited(R, vector<int>(C, 0));
        int res = 0;
        bool match = false;
        int ti = -1;
        int tj = -1;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] > 0) {
                    ti = i;
                    tj = j;
                }
                if (grid[i][j] > 0 && canBeStartPoint(grid, i, j, R, C)) {
                    match = true;
                    dfs(grid, i, j, R, C, visited, 0, res);
                }
            }
        }
        if (ti != -1 && !match) {
            dfs(grid, ti, tj, R, C, visited, 0, res);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/9e6b8acc118bd00a9da822f43fd664398e7843ed3b2b01f5063f7d079b22d2c6-image.png)



