只要考虑左边一列和上面一行和他相邻的就可以了，注意如果grid[i][j]如果为0的话得跳过，否则就会多减点
```cpp
    int surfaceArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = m ? grid[0].size() : 0;
        if (!m || !n) return 0;

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                ans += grid[i][j] * 6 - (grid[i][j] - 1) * 2;
                if (i - 1 >= 0) ans -= 2 * min(grid[i-1][j], grid[i][j]);
                if (j - 1 >= 0) ans -= 2 * min(grid[i][j-1], grid[i][j]);
            }
        }
        return ans;
    }
```