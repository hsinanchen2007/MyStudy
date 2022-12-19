### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;

        for (int i = 0; i < m; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (grid[i][j] != 0)
                    res += 2;
                if (i == 0 || grid[i - 1][j] < grid[i][j]) {
                    res += i == 0 ? grid[i][j] : (grid[i][j] - grid[i - 1][j]);
                }

                if (j == 0 || grid[i][j - 1] < grid[i][j]) {
                    res += j == 0 ? grid[i][j] : (grid[i][j] - grid[i][j - 1]);
                }
                


                if (i == m - 1 || grid[i + 1][j] < grid[i][j]) {
                    res += (i == m - 1) ? grid[i][j] : (grid[i][j] - grid[i + 1][j]);
                } 

                if (j == n - 1 || grid[i][j + 1] < grid[i][j]) {
                    res += (j == n - 1) ? grid[i][j] : (grid[i][j] - grid[i][j + 1]);
                }
                //cout <<"(" << i <<"," << j << ") :" << res << endl;
            }
        }

        return res;

    }
};
```