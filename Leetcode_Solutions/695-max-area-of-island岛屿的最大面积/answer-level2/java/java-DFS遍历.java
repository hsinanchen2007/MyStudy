### 解题思路
从矩阵每个节点开始遍历，遇到值为1的就累加1，遍历完后值置为0

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        
        if(grid==null || grid.length==0 || grid[0].length == 0){
            return 0;
        }
        int row = grid.length;
        int col = grid[0].length;

        int maxArea = 0,cur = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] ==1){
                    cur = dfsIsland(grid,i,j,row,col);
                }
                maxArea = Math.max(maxArea,cur);
            }
        }
        return maxArea;

    }

    private int dfsIsland(int[][] grid, int i, int j, int row, int col) {
        if(i<0 || i>=row || j<0 || j>=col){
            return 0;
        }
        if(grid[i][j] ==1){
            grid[i][j] =0;
            return 1+dfsIsland(grid,i-1,j,row,col)
                    + dfsIsland(grid,i+1,j,row,col)
                    + dfsIsland(grid,i,j-1,row,col)
                    + dfsIsland(grid,i,j+1,row,col);
        }
        return 0;
       
    }
}
```