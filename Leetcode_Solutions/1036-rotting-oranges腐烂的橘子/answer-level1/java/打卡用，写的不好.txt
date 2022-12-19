```
class Solution {
    private class RottenOrange {
        public int x;
        public int y;
        public RottenOrange(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private LinkedList<RottenOrange> queue = new LinkedList<>();
    private int rows;
    private int cols;

    public int orangesRotting(int[][] grid) {
        if (grid.length < 1 || grid[0].length < 1) {
            return -1;
        }

        rows = grid.length;
        cols = grid[0].length;
        if (rows == 1 && cols == 1 && grid[0][0] == 0) {
            return 0;
        }
        int res = 0;
        int sum = 0;
        int rottenCount = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] > 0) sum++;
            }
        }

        while (sum > rottenCount) {
            res++;
            int preCount = rottenCount;
            rottenCount = 0;

            while (!queue.isEmpty()) {
                RottenOrange orange = queue.poll();
                grid[orange.x][orange.y] = 2;
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j] == 2) {
                        infect(i, j, grid);
                        grid[i][j] = 3;
                    }
                    if (grid[i][j] > 1) {
                        rottenCount++;
                    }
                }
            }
            if (rottenCount == sum) {
                break;
            }
            if (rottenCount == preCount) {
                return -1;
            }
        }
        return res - 1;
    }

    private void infect(int row, int col, int[][] grid) {
        doInfect(row - 1, col, grid);
        doInfect(row + 1, col, grid);
        doInfect(row, col - 1, grid);
        doInfect(row, col + 1, grid);
    }

    private void doInfect(int row, int col, int[][] grid) {
        if (!(row < 0 || col < 0 || row >= rows || col >= cols) && grid[row][col] > 0) {
            queue.offer(new RottenOrange(row, col));
        }
    }
}
```
