```
    public int surfaceArea(int[][] grid) {
    if (grid.length == 0) {
            return 0;
        }
        int sum = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if(grid[i][j]==0){
                    continue;
                }
                sum += grid[i][j] * 4 + 2;
                if (i - 1 >= 0) {
                    sum -= Math.min(grid[i][j], grid[i - 1][j]);
                }
                if (i + 1 < grid.length) {
                    sum -= Math.min(grid[i][j], grid[i + 1][j]);
                }
                if (j - 1 >= 0) {
                    sum -= Math.min(grid[i][j], grid[i][j - 1]);
                }
                if (j + 1 < grid[0].length) {
                    sum -= Math.min(grid[i][j], grid[i][j + 1]);
                }

            }
        }
        return sum;
    }
```
