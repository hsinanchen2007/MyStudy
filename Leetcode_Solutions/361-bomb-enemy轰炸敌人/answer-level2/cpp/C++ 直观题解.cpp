```
class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        int res = 0;
        vector<vector<int> > counts(R, vector<int>(C, 0));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 'E') {
                    int r = i;
                    int c = j;
                    for (int k = 0; k < 4; ++k) {
                        int nr = r + dirs[k][0];
                        int nc = c + dirs[k][1];
                        while (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] != 'W') {
                            if (grid[nr][nc] == '0') {
                                ++counts[nr][nc];
                                res = max(res, counts[nr][nc]);
                            }
                            nr += dirs[k][0];
                            nc += dirs[k][1];
                        }
                    }
                }
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/c383203999fbd0c78ec6ce81f99de8c13ab90c7f4ea08078fb8122fc7d463266-image.png)
