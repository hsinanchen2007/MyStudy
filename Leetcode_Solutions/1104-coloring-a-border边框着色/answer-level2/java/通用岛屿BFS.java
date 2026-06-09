```
class Solution {
    private int[][] dirArr = new int[][]{{1,0},{0,1},{-1,0},{0,-1}};

    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        int row = grid.length, col = grid[0].length;
        boolean[][] visited = new boolean[row][col];
        int tColor = grid[r0][c0];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{r0, c0});
        visited[r0][c0] = true;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] pArr = queue.poll();
                int r = pArr[0], c = pArr[1];
                for (int[] dir : dirArr) {
                    int nR = r + dir[0], nC = c + dir[1];
                    if (inArea(grid, nR, nC)) {
                        if (visited[nR][nC]) {
                            continue;
                        }
                        if (grid[nR][nC] == tColor) {
                            queue.add(new int[]{nR, nC});
                            visited[nR][nC] = true;
                        } else {
                            grid[r][c] = color;
                        }
                    } else {
                        grid[r][c] = color;
                    }
                }
            }
        }
        return grid;
    }

    private boolean inArea(int[][] grid, int r, int c) {
        return r >= 0 && r < grid.length && c >= 0 && c < grid[0].length;
    }
}
```
