### 解题思路
从所有陆地坐标开始进行多源BFS。

### 代码

```cpp
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j]) {
                    dist[i][j] = 0;
                    q.push(make_pair(i, j));
                }
        int ans = -1;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int ni = i + dy[k], nj = j + dx[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m || dist[ni][nj] != -1)
                    continue;
                dist[ni][nj] = dist[i][j] + 1;
                ans = max(ans, dist[ni][nj]);
                q.push(make_pair(ni, nj));
            }
        }
        return ans;
    }
};
```