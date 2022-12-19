```
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        vector<int> row_max(R, 0);
        vector<int> col_max(C, 0);
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                row_max[i] = max(row_max[i], grid[i][j]);
                col_max[j] = max(col_max[j], grid[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                res += min(row_max[i], col_max[j]) - grid[i][j];
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/446c2811a311db51de371c43bc7044173cd6b913ef9508d12377815906cd3697-image.png)
