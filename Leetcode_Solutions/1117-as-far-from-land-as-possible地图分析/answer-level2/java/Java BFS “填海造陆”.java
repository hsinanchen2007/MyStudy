思路：一看到最值，首先想到BFS。我们可以先找出所有的陆地，然后从陆地开始向外进行BFS式的扩散，然后每扩散一层就将计数器加一，不断“填海造陆”直到整个地图再也不存在海洋为止。这个时候的计数器就是最远的海洋距离陆地的距离。
```java
class Solution {
    public int maxDistance(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    queue.offer(new int[]{i, j});
                }
            }
        }
        if (queue.isEmpty() || queue.size() == m * n) return -1;
        int[][] next = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        int level = -1;
        while (!queue.isEmpty()) {
            int count = queue.size();
            for (int i = 0; i < count; i++) {
                int[] cur = queue.poll();
                for (int[] nt: next) {
                    int nx = cur[0] - nt[0], ny = cur[1] - nt[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        queue.offer(new int[]{nx, ny});
                    }
                }
            }
            level++;
        }
        return level;
    }
}
```
