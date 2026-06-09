### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    
    public int maxAreaOfIsland(int[][] grid) {
        int row = grid[0].length;
        int col = grid.length;    
        boolean counted[][] = new boolean[col][row];   
        int max = 0;
        int current;
        for(int i=0;i<col;i++)
        {
            for(int j=0;j<row;j++)
            {
                counted[i][j]=false;
            }
        }
        for(int i=0;i<col;i++)
        {
            for(int j=0;j<row;j++)
            {
                if(grid[i][j]==1&&counted[i][j]==false)
                {
                    current = find(grid,counted,i,j);
                    if(max<current)
                    {
                        max = current;
                    }
                }
            }
        }
        return max;
    }

    public int find(int[][] grid, boolean[][] counted, int i, int j)
    {
        int total = 1;
        counted[i][j]=true;
        int row = grid[0].length;
        int col = grid.length;
        if(i<col-1&&counted[i+1][j]==false&&grid[i+1][j]==1)
        {
            total+=find(grid,counted,i+1,j);
        }
        if(i>0&&counted[i-1][j]==false&&grid[i-1][j]==1)
        {
            total+=find(grid,counted,i-1,j);
        }
        if(j<row-1&&counted[i][j+1]==false&&grid[i][j+1]==1)
        {
            total+=find(grid,counted,i,j+1);
        }
        if(j>0&&counted[i][j-1]==false&&grid[i][j-1]==1)
        {
            total+=find(grid,counted,i,j-1);
        }
        return total;
    }
}
```