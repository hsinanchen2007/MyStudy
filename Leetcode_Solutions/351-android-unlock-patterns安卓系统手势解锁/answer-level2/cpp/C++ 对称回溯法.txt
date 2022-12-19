思路简单，详细见代码
```
class Solution {
public:
    void backtrace(vector<vector<bool> >& visited, vector<vector<int> >& path, int m, int n, int& res) {
        int s = path.size();
        if (s > n) return;
        if (s >= 2) {
            auto curr = path.back();
            auto prev = *(path.rbegin() + 1);
            if ((curr[0] + prev[0]) % 2 == 0 && (curr[1] + prev[1]) % 2 == 0) {
                int mx = (curr[0] + prev[0]) / 2;
                int my = (curr[1] + prev[1]) / 2;
                if (!visited[mx][my]) return;
            }
        }
        if (s >= m && s <= n) ++res;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    path.push_back({i, j});
                    backtrace(visited, path, m, n, res);
                    visited[i][j] = false;
                    path.pop_back();
                }
            }
        }
    }
    int numberOfPatterns(int m, int n) {
        vector<vector<bool> > visited(3, vector<bool>(3, false));
        vector<vector<int> > path;
        int res = 0;
        int starts[2][2] = {{0, 0}, {0, 1}}; // 由于对称性，只需要判断边中点、角定点两个情况乘以4即可
        for (int i = 0; i < 2; ++i) {
            int r = 0;
            int x = starts[i][0];
            int y = starts[i][1];
            visited[x][y] = true;
            path.push_back({x, y});
            backtrace(visited, path, m, n, r);
            visited[x][y] = false;
            path.pop_back();
            res += 4 * r;
        }
        visited[1][1] = true; // 计算从中心开始的情况
        path.push_back({1, 1});
        backtrace(visited, path, m, n, res);
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/94c7fee14de701118c2dbb9554ad911488c9fcf732d59449309885d0ac281320-image.png)
