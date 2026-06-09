```
class Solution {
    public int maxDistance(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        int res = 0;
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1)
                    queue.offer(new int[]{i, j});
            }
        }
        if (queue.size() == 0 || queue.size() == row * col)
            return -1;
        while (!queue.isEmpty()) {
            int n = queue.size();
            for (int i = 0; i < n; i++) {
                int[] area = queue.poll();
                int x = area[0];
                int y = area[1];
                for (int j = 0; j < 4; j++) {
                    int newX = x + dx[j];
                    int newY = y + dy[j];
                    if (newX < 0 || newX >= row || newY < 0 || newY >= col || grid[newX][newY] == 1)
                        continue;
                    grid[newX][newY] = 1;
                    queue.offer(new int[]{newX, newY});
                }
            }
            res++;
        }
        return res - 1;
    }
}
```
