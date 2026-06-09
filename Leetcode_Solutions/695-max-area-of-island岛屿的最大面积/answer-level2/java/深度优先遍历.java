```
    public int maxAreaOfIsland(int[][] grid) {
        int res = 0;
        for (int i=0; i<grid.length; i++){
            for (int j=0; j<grid[0].length; j++){
                if (grid[i][j] == 1){
                    res = Math.max(res, dfs(grid, i, j));
                }
            }
        }
        return res;
    }

    private int dfs(int[][] grid, int i, int j) {
        if (i<0 || i>=grid.length || j<0 || j>=grid[0].length || grid[i][j] == 0){
            return 0;
        }
        grid[i][j] = 0;
        int num = 1;
        num += dfs(grid, i-1, j);
        num += dfs(grid, i+1, j);
        num += dfs(grid, i, j-1);
        num += dfs(grid, i, j+1);
        return num;
    }
```
