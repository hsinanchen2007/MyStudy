```
class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool isKey(char c) {
        return c >= 'a' && c <= 'z';
    }
    bool isDoor(char c) {
        return c >= 'A' && c <= 'Z';
    }
    bool isWall(char c) {
        return c == '#';
    }
    bool valid(int r, int c, int R, int C) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        if (grid.empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        queue<vector<int> > q;
        int keys = 0;
        int start_r;
        int start_c;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == '@') {
                    start_r = i;
                    start_c = j;
                    q.push({i, j, 0});
                } else if (isKey(grid[i][j])) {
                    ++keys;
                }
            }
        }
        int K = 1 << keys;
        vector<vector<vector<bool> > > seen(R, vector<vector<bool> >(C, vector<bool>(K, false)));
        seen[start_r][start_c][0] = true;
        int step = 0;
        while (!q.empty()) {
            ++step;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto v = q.front();
                q.pop();
                int r = v[0];
                int c = v[1];
                int s = v[2];
                for (int j = 0; j < 4; ++j) {
                    int nr = r + dirs[j][0];
                    int nc = c + dirs[j][1];
                    int ns = s;
                    if (!valid(nr, nc, R, C)) continue;
                    char tc = grid[nr][nc];
                    if (isWall(tc)) continue;
                    if (isDoor(tc) && (s & (1 << (tc - 'A'))) == 0) continue;
                    if (isKey(tc)) {
                        ns |= 1 << (tc - 'a');
                        if (ns == K - 1) return step;
                    }
                    if (seen[nr][nc][ns]) continue;
                    q.push({nr, nc, ns});
                    seen[nr][nc][ns] = true;
                }
            }
        }
        return -1;
    }
};
```

![image.png](https://pic.leetcode-cn.com/4e8500e8b2f1f7ecfded692b9b024791e0fe9c3120c2b93a846d543276b9dec3-image.png)


