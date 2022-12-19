
```java
class Solution {
    private int max = 0;
    private int count = 0;
    public int maxAreaOfIsland(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int[][] visited = new int[row][col];
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    count = 0;
                    dfs(i,  j , grid);
                    max = Math.max(count, max);
                    count = 0;
                }
            }
        }
        return max;
    }
    private void dfs(int i, int j, int[][] grid) {
        grid[i][j] = 0;
        count++;
        if( i - 1 >=0 && i - 1 < grid.length && grid[i-1][j] == 1) {
            dfs(i-1,  j , grid);
        }
        if( i + 1 >=0 && i + 1 < grid.length && grid[i+1][j] == 1) {
            dfs(i+1,  j , grid);
        }
        if( j - 1 >=0 && j - 1 < grid[0].length && grid[i][j-1] == 1) {
            dfs(i,  j-1 , grid);
        }
        if( j + 1 >=0 && j + 1 < grid[0].length && grid[i][j+1] == 1) {
            dfs(i,  j+1 , grid);
        }

    }
}
```

