判断来的方向是否合理
```cpp
class Solution {
public:
    using pi = pair<int, int>;
    const pi l = {0, -1};
    const pi r = {0, 1};
    const pi u = {-1 ,0};
    const pi d = {1, 0};
    bool hasValidPath(vector<vector<int>>& g) {
        vector<set<pi>> dir = {{l, r}, {u, d}, {l, d}, {r, d}, {l, u}, {r, u}};
        int m = g.size(), n = g[0].size();
        if (m == n && m == 1) return true;
        for (auto [x, y] : dir[g[0][0]-1]) { // 起点有两种方向
            int vis[m][n] = {};
            vis[0][0] = 1;
            pi from = {-x, -y};
            while (1) {
                if (x < 0 || x >= m || y < 0 || y >= n || vis[x][y]) break;
                vis[x][y] = 1;
                auto dset = dir[g[x][y] - 1];
                if (!dset.count(from)) {
                    break;
                }
                if (x == m - 1 && y == n - 1) return true;
                // move next
                dset.erase(from);
                auto [dx, dy] = *begin(dset);
                x += dx;
                y += dy;
                from = {-dx, -dy};
            }
        }
        return false;
    }
};
```