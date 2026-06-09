    // 记录行号;
    private int rowNumber;
    // 记录列数量;
    private int columnNumber;

    // 标记是否记录
    private boolean[][] visited;

    private int currentCount = 0;

    private int islandCount = 0;
    private int[] xDir = new int[]{-1, 0, 1, 0};
    private int[] yDir = new int[]{0, -1, 0, 1};

    public int numIslands(char[][] grid) {
        if (grid.length == 0) {
            return 0;
        }
        if (grid[0].length == 0) {
            return 0;
        }
        rowNumber = grid.length;

        columnNumber = grid[0].length;

        visited = new boolean[rowNumber][columnNumber];
        for (int i = 0; i < rowNumber; i++) {
            for (int j = 0; j < columnNumber; j++) {
                dfs(grid, i, j);
                // 本轮访问完看下是否大于1
                if (currentCount > 0) {
                    islandCount++;
                    // 归零
                    currentCount = 0;
                }
            }
        }
        return islandCount;
    }

    private void dfs(char[][] grid, int i, int j) {

        if (i >= 0 && i < rowNumber && j >= 0 && j < columnNumber) {
            // 标记是否走过
            if (!visited[i][j]) {
                visited[i][j] = true;
                if (grid[i][j] == '1') {
                    for (int k = 0; k < 4; k++) {
                        int nexX = i + xDir[k];
                        int newY = j + yDir[k];
                        dfs(grid, nexX, newY);
                    }
                    currentCount++;
                } else {
                    visited[i][j] = true;
                }
            }
        }
    }