public int maxAreaOfIsland(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }
        int[][]visit = new int[grid.length][grid[0].length];
        int max = 0;
        int size = 0;
        for (int row = 0; row < grid.length; row++) {
            for (int col = 0; col < grid[0].length; col++) {
                size = dfs(row, col, grid, visit);
                if (size > max) {
                    max = size;
                }
            }
        }
        return max;
    }

    public int dfs(int row, int col, int[][] grid, int[][] visit) {
        if (row >= 0 && row < grid.length && col >= 0 && col < grid[0].length) {
            if (grid[row][col] == 1 && visit[row][col] == 0) {
                visit[row][col] = 1;
                return dfs(row,col - 1,grid,visit) + dfs(row,col + 1,grid,visit) +
                        dfs(row - 1,col,grid,visit) + dfs(row + 1,col,grid,visit) + 1;
            }
        }
        return 0;
    }