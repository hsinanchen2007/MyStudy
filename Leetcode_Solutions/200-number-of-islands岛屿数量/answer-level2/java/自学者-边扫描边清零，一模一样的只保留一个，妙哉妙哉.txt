### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    
    private void dfs(char[][] grid,int row,int col) {
        int rowLen = grid.length;
        int colLen = grid[0].length;
        if(row < 0 || col < 0 || row >= rowLen || col >= colLen || grid[row][col] == '0') {
            //如果越界直接返回
            return;
        }
        //当前节点已经搜索过了，直接设置为‘0’
        grid[row][col] = '0';
        
        //向上走一步
        dfs(grid,row - 1, col);
         //向下走一步
        dfs(grid,row + 1, col);
        //向左走一步
        dfs(grid,row,col-1);
        //向右走一步
        dfs(grid,row,col+1);
    }
    
    public int numIslands(char[][] grid) {
        if(grid == null || grid.length == 0) {
            // 空岛屿直接返回0个古道孤岛
            return 0;
        }
        int rowLen = grid.length;
        int colLen = grid[0].length;
        int numIslands = 0;
        for (int row = 0; row < rowLen; ++row) {
          for (int col = 0; col < colLen; ++col) {
            if (grid[row][col] == '1') {
              ++numIslands;
              dfs(grid, row, col);
            }
          }
        }
        return numIslands;
    }
}
```