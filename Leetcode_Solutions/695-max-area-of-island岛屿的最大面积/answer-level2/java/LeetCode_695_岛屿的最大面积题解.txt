### 解题思路

- DFS 依次递归遍历值为1周围的上下左右中值为1的节点 2ms
- BFS 每次将值为1的节点的周围岛屿放入队列，重复这一步并记数 5ms

### 代码

```java
class Solution {

        public int maxAreaOfIsland(int[][] grid) {
            Queue<int[]> queue = new LinkedList<>();
        int maxArea = 0;
        // 上下左右位移位置
        int[][] move = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                int num = 0;
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    queue.add(new int[]{i, j});
                    while (queue.size() != 0) {
                        int[] poll = queue.poll();
                        num ++;
                        for (int k = 0; k < move.length; k++) {
                            int row = poll[0] + move[k][0];
                            int col = poll[1] + move[k][1];
                            if (row >= 0 && col >= 0 && row < grid.length && col < grid[0].length && grid[row][col] == 1) {
                                queue.offer(new int[]{row, col});
                                grid[row][col] = 0;
                            }
                        }
                    }
                    maxArea = Math.max(maxArea, num);
                }
            }
        }
        return maxArea;
    }


    public int maxAreaOfIslandNew(int[][] grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    maxArea = Math.max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }

    private int dfs(int[][] grid, int i, int j) {
        // 将不符合条件的都返回0
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] == 0) {
            return 0;
        }

        int num = 1; // 因为本身传进来的数据就是1
        grid[i][j] = 0; // 将遍历过的岛屿本身置为0 沉岛

        // 深度遍历其上下节点
        num += dfs(grid, i + 1, j);
        num += dfs(grid, i - 1, j);
        // 左右节点
        num += dfs(grid, i, j + 1);
        num += dfs(grid, i, j - 1);
        return num;
    }
}

```