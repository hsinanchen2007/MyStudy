```
class Solution {
    public int islandPerimeter(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        
        int count = 0, target = 0;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++){
                if(grid[i][j]==1 && j+1<col && grid[i][j+1]==1)
                    target++;
                if(grid[i][j]==1 && i+1<row && grid[i+1][j]==1)
                    target++;
                if(grid[i][j] == 1)
                    count++;
            }
        return 4 * count - 2 * target;
    }
}
```
