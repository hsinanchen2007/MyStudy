### 解题思路
BFS

### 代码

```java
class Solution {
    private static final int[][] DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    public static int orangesRotting(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int minutes = 0;
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    queue.offer(new int[]{i, j});
                }
            }
        }

        minutes = bfs(grid, queue);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return minutes;
    }

    private static int bfs(int[][] grid, Queue<int[]> queue) {
        int minutes = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            boolean hasRotten = false;
            while (size-- > 0) {
                int[] curr = queue.poll();

                for (int[] direction : DIRECTIONS) {
                    int neighborX = curr[0] + direction[0];
                    int neighborY = curr[1] + direction[1];

                    if (neighborX < 0 || neighborX >= grid.length
                        || neighborY < 0 || neighborY >= grid[0].length) {
                        continue;
                    }

                    if (grid[neighborX][neighborY] == 1) {
                        grid[neighborX][neighborY] = 2;
                        hasRotten = true;
                        queue.offer(new int[]{neighborX, neighborY});
                    }
                }
            }
            if (hasRotten) {
                minutes++;
            }
        }

        return minutes;
    }
}
```