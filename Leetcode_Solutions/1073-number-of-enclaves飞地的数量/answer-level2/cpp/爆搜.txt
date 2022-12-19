老铁们，这题不用并查集，别秀了嗷。直接从四个边界开始爆搜就完了。
```c++
class Solution {
public:
  int numEnclaves(vector<vector<int>>& A) {
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    int n = A.size(), m = A[0].size();
    int ret = 0;

    function<int(int, int)> ok = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m;
    };

    function<void(int, int)> dfs = [&](int x, int y) {
      A[x][y] = 2;
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (!ok(xx, yy) || A[xx][yy] != 1) continue;
        dfs(xx, yy);
      }
    };

    for (int i = 0; i < n; i++) {
      if (A[i][0] == 1) dfs(i, 0);
      if (A[i][m - 1] == 1) dfs(i, m - 1);
    }
    for (int i = 0; i < m; i++) {
      if (A[0][i] == 1) dfs(0, i);
      if (A[n - 1][i] == 1) dfs(n - 1, i);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (A[i][j] == 1) ret++;
      }
    }
    return ret;
  }
};
```