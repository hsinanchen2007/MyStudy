```
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
class Solution {
private:
    int sx, sy, ex, ey, n, m;
    bool dfs(vector<vector<int>>& grid, int x, int y)
    {
        if (x == ex && y == ey)
            return true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == 1) {
                continue;
            }
            grid[nx][ny] = 1;
            if (dfs(grid, nx, ny)) {
                return true;
            }
        }
        return false;
    }

public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target)
    {
        vector<int> rows, cols;
        rows.push_back(0), rows.push_back(1e6 - 1);
        cols.push_back(0), cols.push_back(1e6 - 1);
        for (vector<int>& tmp : blocked) {
            rows.push_back(tmp[0]), cols.push_back(tmp[1]);
        }
        rows.push_back(source[0]), rows.push_back(source[1]);
        cols.push_back(target[0]), cols.push_back(target[1]);
        sort(rows.begin(), rows.end()), sort(cols.begin(), cols.end());
        rows.erase(unique(rows.begin(), rows.end()), rows.end());
        cols.erase(unique(cols.begin(), cols.end()), cols.end());
        n = rows.size(), m = cols.size();
        vector<vector<int>> grid(n, vector<int>(m));
        for (vector<int>& tmp : blocked) {
            int x = lower_bound(rows.begin(), rows.end(), tmp[0]) - rows.begin();
            int y = lower_bound(cols.begin(), cols.end(), tmp[1]) - cols.begin();
            grid[x][y] = 1;
        }
        sx = lower_bound(rows.begin(), rows.end(), source[0]) - rows.begin();
        sy = lower_bound(cols.begin(), cols.end(), source[1]) - cols.begin();
        ex = lower_bound(rows.begin(), rows.end(), target[0]) - rows.begin();
        ey = lower_bound(cols.begin(), cols.end(), target[1]) - cols.begin();

        grid[sx][sy] = 1;
        return dfs(grid, sx, sy);
    }
};
```
![Screenshot from 2019-12-06 12-17-20.png](https://pic.leetcode-cn.com/dcb1ffcd7eef3bf63a51a2e736d1a1024e2123dc86b8957dddb5f8bc002f14a7-Screenshot%20from%202019-12-06%2012-17-20.png)

