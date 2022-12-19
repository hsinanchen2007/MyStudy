```c++
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int s = 0;
        for (int i = 0; i < n; i++) {
            int x = 0, y = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) s++;
                x = max(x, grid[i][j]); // max element in row
                y = max(y, grid[j][i]); // max element in col
            }
            s += x;
            s += y;
        }
        return s;
    }
};
```