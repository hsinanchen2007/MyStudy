### 代码

```cpp
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int row_size = grid.size();
        int col_size = grid[0].size();

        vector<int> row_max(row_size , -1);
        vector<int> col_max(col_size , -1);

        for(int i = 0 ; i < row_size ; ++i) {
            for(int j = 0 ; j < col_size ; ++j) {
                row_max[i] = max(row_max[i] , grid[i][j]);
                col_max[j] = max(col_max[j] , grid[i][j]);
            }
        }

        int sum = 0;
        for(int i = 0 ; i < row_size ; ++i) {
            for(int j = 0 ; j < col_size ; ++j) {
                sum += min(row_max[i] , col_max[j]) - grid[i][j];
            }
        }
        return sum;
    }
};
```