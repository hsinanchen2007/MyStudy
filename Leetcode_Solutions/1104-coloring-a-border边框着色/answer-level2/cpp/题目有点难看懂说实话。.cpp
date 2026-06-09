- 就是边界(第一行，列，最后一行，列) 或者这个点上下左右四个中有一个不是grid[r0][c0]则需要
- 改变成题目给的color。所以我们为了能判断四边使用一个res = grid.以及和同等大小的visit来
- 记录已经访问过的点


```
class Solution {
public:
    int color1 = 0;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> visit;
    vector<vector<int>> res;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        color1 = grid[r0][c0];
        if (color1 == color) return grid;
        res = grid;
        visit.resize(grid.size(), vector<int>(grid[0].size()));
        visit[r0][c0] = 1;
        dfs(grid, r0, c0, color);
        return res;
    } 
    void dfs(vector<vector<int>>& grid, int r, int c, int color) {
        if (r == 0 || c == 0 || r == grid.size() - 1 || c == grid[0].size() - 1) {
            res[r][c] = color; 
        }
        for (int i = 0; i < 4; ++i) {
            int x = dir[i][0] + r, y = dir[i][1] + c;
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) continue;
            if (grid[x][y] != color1) {
                res[r][c] = color; continue;
            }
            if (visit[x][y]) continue;
            visit[x][y] = 1;
            dfs(grid, x, y, color);
        }
    }
};
```
- 广度优先遍历实现。实际上只要点不是在边界就不会出现与dir[4][2]数组相加后出现越界的情况。
- 一旦出现正好说明此时访问的这个点是属于边界。


```
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int color1 = grid[r0][c0];
        if (color1 == color) return grid;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(grid), visit(m, vector<int>(n));
        visit[r0][c0] = 1;
        queue<pair<int, int>> qu; qu.push({r0, c0});
        while (!qu.empty()) {
            int x = qu.front().first, y = qu.front().second;
            qu.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = dir[i][0] + x, ny = dir[i][1] + y;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == color1) {
                    if (!visit[nx][ny]) {
                        visit[nx][ny] = 1; qu.push({nx, ny});
                    }
                }
                else res[x][y] = color;
            }
        }
        return res;
    }
};
```
