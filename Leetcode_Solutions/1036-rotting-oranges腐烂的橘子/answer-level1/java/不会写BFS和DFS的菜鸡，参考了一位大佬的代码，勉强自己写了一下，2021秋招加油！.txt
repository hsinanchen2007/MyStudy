```
class Solution {
    public int orangesRotting(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int count = 0;
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1)
                    count++;
                else if (grid[i][j] == 2)
                    queue.offer(new int[]{i, j});
            }
        }
        int minute = 0;
        while (count > 0 && !queue.isEmpty()) {
            minute++;
            int n = queue.size();
            for (int i = 0; i < n; i++) {
                int[] t = queue.poll();
                int r = t[0];
                int c = t[1]; 
                if (r > 0 && grid[r - 1][c] == 1) {
                    count--;
                    grid[r - 1][c] = 2;
                    queue.offer(new int[]{r - 1, c});
                }
                if (r < row - 1 && grid[r + 1][c] == 1) {
                    count--;
                    grid[r + 1][c] = 2;
                    queue.offer(new int[]{r + 1, c});
                }
                if (c > 0 && grid[r][c - 1] == 1) {
                    count--;
                    grid[r][c - 1] = 2;
                    queue.offer(new int[]{r, c - 1});
                }
                if (c < col - 1 && grid[r][c + 1] == 1) {
                    count--;
                    grid[r][c + 1] = 2;
                    queue.offer(new int[]{r, c + 1});
                }
            }
        }
        if (count > 0)
            return -1;
        return minute;
    }
}
```
