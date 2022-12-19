* 暴力求解， 找到所有陆地，然后遍历所有海洋，找到每个海洋和陆地的距离的最小值，然后在最小值中找最大值  会超时

* bfs， 从每个陆地出发层次遍历（广度优先遍历），每遍历到一个元素标记已访问，看最大能到多少层

bfs经典板子（带层次信息）：
```
int layer = 0;
while (!queue.isEmpty()) {
    layer++;
    // queue中的内容一次取出, 每次循环处理一层
    int n = queue.size();
    while (n-- > 0) {
        Object obj = queue.poll();
        if (满足条件) {
            queue.offer(obj的下一个元素);
        }
    }
}
```


```
    public int maxDistance(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return -1;
        }
        int N = grid.length;
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    int[] pos = {i, j};
                    queue.add(pos);
                }                
            }
        }
        if (queue.size() == 0 || queue.size() == N * N) {
            return -1;
        }
        int distance = -1;
        while (!queue.isEmpty()) {
            distance++;
            int n = queue.size();
            while (n-- > 0) {
                int[] pos = queue.poll();
                // 上
                if (pos[0] - 1 >= 0 && grid[pos[0] - 1][pos[1]] == 0) {
                    int[] p = {pos[0] - 1, pos[1]};
                    queue.offer(p);
                    grid[pos[0] - 1][pos[1]] = 2;
                }
                // 下
                if (pos[0] + 1 < N && grid[pos[0] + 1][pos[1]] == 0) {
                    int[] p = {pos[0] + 1, pos[1]};
                    queue.offer(p);
                    grid[pos[0] + 1][pos[1]] = 2;
                }
                // 左
                if (pos[1] - 1 >= 0 && grid[pos[0]][pos[1] - 1] == 0) {
                    int[] p = {pos[0], pos[1] - 1};
                    queue.offer(p);
                    grid[pos[0]][pos[1] - 1] = 2;
                }
                // 右
                if (pos[1] + 1 < N && grid[pos[0]][pos[1] + 1] == 0) {
                    int[] p = {pos[0], pos[1] + 1};
                    queue.offer(p);
                    grid[pos[0]][pos[1] + 1] = 2;
                }
            }
        }
        return distance;
    }
```