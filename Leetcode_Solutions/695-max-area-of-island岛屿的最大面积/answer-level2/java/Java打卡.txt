### 解题思路
Java打卡

### 代码

```java
class Solution {
    int[] dx = {0, 1, 0, -1};
    int[] dy = {1, 0, -1, 0};

    public int maxAreaOfIsland(int[][] grid) {
        if (grid == null || grid.length == 0)
            return 0;
        int maxArea = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    maxArea = Math.max(maxArea, BFS(grid, i, j));
                }
            }
        }

        return maxArea;

    }

    private int BFS(int[][] grid, int i, int j) {
        int area = 0;
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{i, j});
        grid[i][j] = 0;
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            area += 1;
            for (int k = 0; k < 4; k++) {
                int x = current[0] + dx[k];
                int y = current[1] + dy[k];
                if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length && grid[x][y] == 1) {
                    grid[x][y] = 0;
                    queue.offer(new int[]{x, y});
                }
            }
        }

        return area;

    }
}
```