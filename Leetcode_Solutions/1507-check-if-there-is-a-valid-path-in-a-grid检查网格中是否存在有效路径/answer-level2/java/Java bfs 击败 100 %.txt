### 代码

```java
class Solution {
    int[][][] dirs;
    public boolean hasValidPath(int[][] grid) {
        int m = grid[0].length;
        int n = grid.length;
        dirs = new int[7][2][2];
        dirs[1] = new int[][]{{0, -1}, {0, 1}};
        dirs[2] = new int[][]{{-1, 0}, {1, 0}};
        dirs[3] = new int[][]{{0, -1}, {1, 0}};
        dirs[4] = new int[][]{{1, 0}, {0, 1}};
        dirs[5] = new int[][]{{0, -1}, {-1, 0}};
        dirs[6] = new int[][]{{-1, 0}, {0, 1}};
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});
        boolean[] visit = new boolean[n * m];
        visit[0] = true;
        while (!q.isEmpty()) {
            int[] top = q.poll();
            int x = top[0];
            int y = top[1];
            for (int[] d : dirs[grid[x][y]]) {
                int dx = x + d[0];
                int dy = y + d[1];
                if (dx < 0 || dx >= n || dy < 0 || dy >= m || visit[dx * m + dy]) continue;
                for (int[] d2 : dirs[grid[dx][dy]]) {
                    if (d2[0] == -d[0] && d2[1] == -d[1]) {
                        visit[dx * m + dy] = true;
                        q.add(new int[]{dx, dy});
                    }
                }
            }
        }
        return visit[(n - 1) * m + m - 1];
    }
}
```