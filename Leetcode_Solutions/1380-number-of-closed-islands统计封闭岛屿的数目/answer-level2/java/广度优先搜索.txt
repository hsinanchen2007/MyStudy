封闭岛屿的要求是不与边界相连，完全被水包围。对于陆地进行广度优先搜索，初始时所有的陆地都未被访问过，每次选择一块未被访问过的陆地开始广度优先搜索。每次广度优先搜索都可以将与该陆地相连（行方向或列方向）的所有陆地都访问过，即从一块陆地开始访问，可将该陆地所在的整个岛屿都访问，在这个过程中记录这块岛屿是否封闭，如果发现任何一块陆地是在边界（根据所在行和列判断），则不封闭，否则就是封闭，发现封闭岛屿则计数加1。一次广度优先搜索之后，再找下一块未被访问过的陆地开始广度优先搜索，必然是另一个岛屿。当所有陆地都访问结束，即可知道封闭岛屿的数量。
```
class Solution {
    final int BLOCK = -1;
    final int WHITE = 0;
    final int GRAY = 1;
    final int BLACK = 2;

    public int closedIsland(int[][] grid) {
        int closedIslands = 0;
        int rows = grid.length, columns = grid[0].length;
        int[][] colors = new int[rows][columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == 1)
                    colors[i][j] = BLOCK;
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (colors[i][j] == WHITE) {
                    int islandClose = bfs(grid, colors, i, j);
                    closedIslands += islandClose;
                }
            }
        }
        return closedIslands;
    }

    public int bfs(int[][] grid, int[][] colors, int startRow, int startColumn) {
        int rows = grid.length, columns = grid[0].length;
        Queue<int[]> queue = new LinkedList<int[]>();
        queue.offer(new int[]{startRow, startColumn});
        boolean flag = true;
        if (startRow == 0 || startRow == rows - 1 || startColumn == 0 || startColumn == columns - 1)
            flag = false;
        while (!queue.isEmpty()) {
            int[] square = queue.poll();
            int row = square[0], column = square[1];
            if (row > 0) {
                int rowUp = row - 1;
                if (colors[rowUp][column] == WHITE) {
                    colors[rowUp][column] = GRAY;
                    queue.offer(new int[]{rowUp, column});
                    if (rowUp == 0)
                        flag = false;
                }
            }
            if (row < rows - 1) {
                int rowDown = row + 1;
                if (colors[rowDown][column] == WHITE) {
                    colors[rowDown][column] = GRAY;
                    queue.offer(new int[]{rowDown, column});
                    if (rowDown == rows - 1)
                        flag = false;
                }
            }
            if (column > 0) {
                int columnLeft = column - 1;
                if (colors[row][columnLeft] == WHITE) {
                    colors[row][columnLeft] = GRAY;
                    queue.offer(new int[]{row, columnLeft});
                    if (columnLeft == 0)
                        flag = false;
                }
            }
            if (column < columns - 1) {
                int columnRight = column + 1;
                if (colors[row][columnRight] == WHITE) {
                    colors[row][columnRight] = GRAY;
                    queue.offer(new int[]{row, columnRight});
                    if (columnRight == columns - 1)
                        flag = false;
                }
            }
            colors[row][column] = BLACK;
        }
        int islandClose = flag ? 1 : 0;
        return islandClose;
    }
}
```