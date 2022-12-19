```
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        while(k--)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=m-1;j>0;j--)
                {
                    int tmp = grid[i][j];
                    grid[i][j] = grid[i][j-1];
                    grid[i][j-1] = tmp;
                }
            }
            for(int i=n-1;i>0;i--)
            {
                int tmp = grid[i][0];
                grid[i][0] = grid[i-1][0];
                grid[i-1][0] = tmp;
            }
        }
        return grid;
    }
};

```