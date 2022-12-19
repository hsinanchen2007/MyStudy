### 解题思路

BFS，优点类似于 leetcode 200. 岛屿的数量，比那道题简单。
但对我来说还是太难了，都是大佬，害怕😨

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        if (grid == null) return 0;

        int[][] directions = new int[][]{{-1,0}, {0,-1}, {1,0}, {0,1}};
        Queue<int[]> queue = new ArrayDeque<>();
        int rows = grid.length;
        int cols = grid[0].length;

        // 将腐烂句子🍊的位置存入队列，一步步感染
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) queue.offer(new int[]{i,j,0});
            }
        }
        // 开始感染了
        int time = 0;
        while (!queue.isEmpty()){
            int[] curr = queue.poll();
            time = curr[2];
            // 四个方向搜索，将好橘子破坏
            for (int k = 0; k < 4; k++) {
                int newX = curr[0] + directions[k][0];
                int newY = curr[1] + directions[k][1];
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2;
                    queue.offer(new int[]{newX, newY, time + 1});
                }
            }
        }

        // 搜索还有没有新鲜的橘子🍊
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return time;   
    }
}
```