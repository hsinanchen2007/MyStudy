根据官方题解的思路写的
```
class Solution {
    public int orangesRotting(int[][] grid) {
        //辅助变量
        int[] dr = new int[]{-1, 0, 1, 0};
        int[] dc = new int[]{0, -1, 0, 1};
        int R = grid.length;
        int C = grid[0].length;

        Queue<int[]> queue = new LinkedList<>();
        int count = 0;  //新鲜橘子的数量
        int time = -1;  //耗时

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 2)
                    queue.add(new int[]{i, j});
                if (grid[i][j] == 1)
                    count++;
            }
        }
        if (count == 0)
            return 0;

        while (!queue.isEmpty()) {
            for (int num = queue.size(); num > 0; num--) {
                int[] a = queue.remove();
                //遍历腐烂橘子的上下左右，同时考虑橘子在数组边缘的情况
                for (int i = 0; i < 4; i++) {
                    int nr = a[0] + dr[i];
                    int nc = a[1] + dc[i];
                    if (0 <= nr && nr < R && 0 <= nc && nc < C && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        queue.add(new int[]{nr, nc});
                        count--;
                    }
                }
            }
            time++;
        }
        if (count != 0)
            return -1;
        return time;
    }
}
```
