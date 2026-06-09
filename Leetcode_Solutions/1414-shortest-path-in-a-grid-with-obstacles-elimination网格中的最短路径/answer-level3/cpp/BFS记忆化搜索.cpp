```c++
class Solution {
public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    const int dx[5] = {0, 0, 1, -1};
    const int dy[5] = {1, -1, 0, 0};
    queue<tuple<int, int, int, int>> q;
    int f[41][41][40*40+1];
    memset(f, -1, sizeof f);
    int n = grid.size(), m = grid[0].size();
    int x, y, t, s;
    q.emplace(0, 0, k, 0);
    f[0][0][k] = 0;

    auto ok = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m;
    };

    while (!q.empty()) {
      tie(x, y, t, s) = q.front(); q.pop();
      if (x == n - 1 && y == m - 1) return s;
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (!ok(xx, yy)) continue;
        if (grid[xx][yy] == 1) {
          if (t == 0) continue;
          if (f[xx][yy][t - 1] != -1) continue;
          f[xx][yy][t - 1] = s + 1;
          q.emplace(xx, yy, t - 1, s + 1);
        } else {
          if (f[xx][yy][t] != -1) continue;
          f[xx][yy][t] = s + 1;
          q.emplace(xx, yy, t, s + 1);
        }
      }
    }
    return -1;
  }
};
```