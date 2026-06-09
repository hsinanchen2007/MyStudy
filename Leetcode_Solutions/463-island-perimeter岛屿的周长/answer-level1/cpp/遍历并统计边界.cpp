```
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int len = 0;
        for (int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(grid[i][j] == 1)
                {
                    if(j==0 || grid[i][j-1] == 0)
                        len++;
                    if(j==cols-1 || grid[i][j+1] == 0)
                        len++;
                    if(i == 0 || grid[i-1][j] ==0)
                        len++;
                    if(i == rows-1 || grid[i+1][j] ==0)
                        len++;                    
                }
            }
        }
        return len;
    }
};
```
