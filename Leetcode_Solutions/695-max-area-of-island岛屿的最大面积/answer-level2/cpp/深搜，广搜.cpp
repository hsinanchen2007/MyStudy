深搜和广搜2种方式

```
class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int res = 0;

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    // res = max(res, bfs(grid, visited, m, n, i, j));
                    res = max(res, dfs(grid, visited, m, n, i, j));
                }
            }
        }
        return res;
    }

   private:
    // 深搜
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int m,
            int n, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] ||
            grid[x][y] == 0) {
            return 0;
        }

        int res = 1;
        visited[x][y] = true;

        vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < 4; i++) {
            res += dfs(grid, visited, m, n, x + d[i][0], y + d[i][1]);
        }
        return res;
    }
    // 广搜
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int m,
            int n, int x, int y) {
        if (visited[x][y] || grid[x][y] == 0) return 0;

        int res = 0;

        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;
        res++;

        vector<vector<int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            pair<int, int> t = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int a = t.first + d[i][0];
                int b = t.second + d[i][1];
                if (a >= 0 && a < m && b >= 0 && b < n && !visited[a][b] &&
                    grid[a][b] == 1) {
                    q.push({a, b});
                    visited[a][b] = true;
                    res++;
                }
            }
        }
        return res;
    }
};

```

时间复杂度：O(M * N), M N 分别为数组行和列数
空间复杂度：O(M * N)，M N 分别为数组行和列数，使用了额外的数组来保存位置是否被访问过。还可以优化到 O(1)，即将 grid 中遍历过的位置置为0，但是会对原数组作更改。