 public static void dfs(char[][] grid, int l, int c) {

        if (l >= grid.length || c >= grid[0].length || l < 0 || c < 0 || grid[l][c] == '0') {
            return;
        }
        grid[l][c] = '0';

        dfs(grid, l-1, c);
        dfs(grid, l + 1, c );
        dfs(grid, l, c + 1);
        dfs(grid, l, c - 1);

    }


    public static int numIslands(char[][] grid) {

        if (grid.length == 0) return 0;
        int num = 0;

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == '1') {
                    num++;
                    dfs(grid, i, j);
                }
            }
        }
        return num;

    }