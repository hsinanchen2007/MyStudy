```
class Solution {
public:
    bool valid(const vector<vector<int> >& grid, int r, int c, int s) {
        for (int i = 0; i < s; ++i) {
            if (grid[r + i][c] + grid[r + i][c + s - 1] + 
                    grid[r][c + i] + grid[r + s - 1][c + i] != 4) 
                return false;
        }
        return true;
    }
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int R = grid.size();
        int C = grid[0].size();
        for (int s = min(R, C); s >= 1; --s) {
            for (int i = 0; i < R && i + s - 1 < R; ++i) {
                for (int j = 0; j < C && j + s - 1 < C; ++j) {
                    if (valid(grid, i, j, s)) return s * s;
                }
            }
        }
        return 0;
    }
};
```

