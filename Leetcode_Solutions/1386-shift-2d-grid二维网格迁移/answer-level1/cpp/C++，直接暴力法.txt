### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> g = grid;
        int n = grid.size();
        int m = grid[0].size();
        while( k > 0 )
        {
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                {
                    
                    if(i == n - 1 && j == m - 1)
                        grid[0][0] = g[ n - 1][ m - 1];
                    else if( j == m - 1 )
                        grid[(i+1) % n][0] = g[i][m-1];
                    else 
                        grid[i][j + 1] = g[i][j];
                }
            g = grid;
            k--;
        }
        return grid;
    }
};
```