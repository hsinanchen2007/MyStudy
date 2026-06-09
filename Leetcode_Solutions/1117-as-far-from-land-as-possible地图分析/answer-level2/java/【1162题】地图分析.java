**方法一：广度优先搜索(BFS)**
```
class Solution {
    /**
    * 思路：
    * (1) 找到地图中所有岛屿位置记录到队列中。
    * (2) 依次从队列中取出陆地扩散遍历海洋，如果遇到海洋则填海继续遍历，否则停止当前遍历。
    * (3) 最后一次遍历到的海洋就是离陆地区域最远的海洋，而且一定是由离它最近的陆地扩散到的。
    */
    public int maxDistance(int[][] grid) {
        int N = grid.length;
        // 配合使用，遍历与当前位置相邻的上下左右四个位置。
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};
        Queue<int[]> queue = new ArrayDeque<>();
        // 先把所有的陆地都入队。
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    queue.offer(new int[] {i, j});
                }
            }
        }
        // 从各个陆地开始，一圈一圈的遍历海洋，最后遍历到的海洋就是离陆地最远的海洋。
        boolean hasOcean = false;
        int[] point = null;
        while (!queue.isEmpty()) {
            point = queue.poll();
            int x = point[0], y = point[1];
            // 取出队列中的岛屿，向其四周扩散，如果是海洋则继续扩散，否则停止扩散。
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX < 0 || newX >= N || newY < 0 || newY >= N || grid[newX][newY] != 0) {
                    continue;
                }
				// 对遍历到的海洋填海操作，并记录离最近岛屿的距离。
                grid[newX][newY] = grid[x][y] + 1;
                hasOcean = true;
                queue.offer(new int[] {newX, newY});
            }
        }
        // 没有陆地或者没有海洋，返回-1。
        if (point == null || !hasOcean) {
            return -1;
        }
        // 返回最后一次遍历到的海洋的距离。
        return grid[point[0]][point[1]] - 1;
    }
}
```
