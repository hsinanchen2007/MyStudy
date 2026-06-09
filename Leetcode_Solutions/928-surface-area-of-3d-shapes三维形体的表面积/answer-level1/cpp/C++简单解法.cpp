### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int N = grid.size(), ans = 0;
        for(int r = 0; r < N; r++)
            for(int c = 0; c < N; c++)
            {
                if(grid[r][c] == 0) continue;
                ans += 2 + grid[r][c] * 4 ;
                if(r > 0) ans -= min(grid[r-1][c], grid[r][c]) * 2;
                if(c > 0) ans -= min(grid[r][c-1], grid[r][c]) * 2;
            }         
        return ans;
    }
};
```