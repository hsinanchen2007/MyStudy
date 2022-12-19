```cpp
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res = 0, N = grid.size();
        for (int i = 0; i < N; ++i) {
            int rowMax = 0;
            int colMax = 0;
            for (int j = 0; j < N; ++j) {
                if (grid[i][j]) ++res;
                rowMax = max(rowMax, grid[i][j]);
                colMax = max(colMax, grid[j][i]);
            }
            res += rowMax + colMax;
        }
        return res;
    }
};
```