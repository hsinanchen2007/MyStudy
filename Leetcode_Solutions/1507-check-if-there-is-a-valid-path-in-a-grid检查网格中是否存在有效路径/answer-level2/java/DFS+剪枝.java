![image.png](https://pic.leetcode-cn.com/08c9e2e427ea36c965a81160d14c637fe13fb931c19aec4896f2927008c00668-image.png)
```
class Solution {

    // 左右上下方向;
    private int[] dx = new int[] {0, 0, -1, 1};

    private int[] dy = new int[] {-1, 1, 0, 0};

    private int Row;

    private int Column;

    private boolean result;

    public boolean hasValidPath(int[][] grid) {
        // 记录是否访问过
        this.Row = grid.length;
        this.Column = grid[0].length;
        boolean[][] visited = new boolean[this.Row][this.Column];
        dfs(grid, visited, 0, 0);
        return result;
    }

    private void dfs(int[][] grid, boolean[][] visited, int x, int y) {
        if (x < 0 || x >= Row || y < 0 || y >= Column) {
            return;
        }
        if (!visited[x][y]) {
            visited[x][y] = true;
            if (x == Row - 1 && y == Column - 1) {
                this.result = true;
                return;
            }
            for (int i = 0; i < 4; i++) {
                int nex = x + dy[i];
                int ney = y + dx[i];
                switch (grid[x][y]) {
                    case 1:
                        if (nex >= 0 && nex < Row && ney >= 0 && ney < Column)
                        // 只能往左或者往右走，剪枝;
                        {
                            if ((i == 2 && (grid[nex][ney] == 4 || grid[nex][ney] == 6 || grid[nex][ney] == 1))
                                || (i == 3 && (grid[nex][ney] == 3 || grid[nex][ney] == 5 || grid[nex][ney] == 1))) {
                                dfs(grid, visited, nex, ney);
                            }
                        }
                        break;
                    case 2:
                        if (nex >= 0 && nex < Row && ney >= 0 && ney < Column) {
                            if ((i == 0 && (grid[nex][ney] == 3 || grid[nex][ney] == 4 || grid[nex][ney] == 2))
                                || (i == 1 && (grid[nex][ney] == 5 || grid[nex][ney] == 6 || grid[nex][ney] == 2))) {
                                dfs(grid, visited, nex, ney);
                            }
                        }
                        break;
                    case 3:
                        if (nex >= 0 && nex < Row && ney >= 0 && ney < Column) {
                            if ((i == 1 && (grid[nex][ney] == 2 || grid[nex][ney] == 5 || grid[nex][ney] == 6))
                                || (i == 2 && (grid[nex][ney] == 1 || grid[nex][ney] == 4 || grid[nex][ney] == 6))) {
                                dfs(grid, visited, nex, ney);
                            }
                        }
                        break;
                    case 4:
                        if (nex >= 0 && nex < Row && ney >= 0 && ney < Column) {
                            if ((i == 1 && (grid[nex][ney] == 2 || grid[nex][ney] == 5 || grid[nex][ney] == 6))
                                || (i == 3 && (grid[nex][ney] == 3 || grid[nex][ney] == 5 || grid[nex][ney] == 1))) {
                                dfs(grid, visited, nex, ney);
                            }
                        }
                        break;
                    case 5:
                        if (nex >= 0 && nex < Row && ney >= 0 && ney < Column) {
                            if ((i == 0 && (grid[nex][ney] == 2 || grid[nex][ney] == 3 || grid[nex][ney] == 4))
                                || (i == 2 && (grid[nex][ney] == 1 || grid[nex][ney] == 4 || grid[nex][ney] == 6))) {
                                dfs(grid, visited, nex, ney);
                            }
                        }
                        break;
                    case 6:
                        if (nex >= 0 && nex < Row && ney >= 0 && ney < Column) {
                            if ((i == 0 && (grid[nex][ney] == 2 || grid[nex][ney] == 3 || grid[nex][ney] == 4))
                                || (i == 3 && (grid[nex][ney] == 1 || grid[nex][ney] == 3 || grid[nex][ney] == 5))) {
                                dfs(grid, visited, nex, ney);
                            }
                        }
                        break;
                }
            }
            visited[x][y] = false;
        }
    }
}
```
