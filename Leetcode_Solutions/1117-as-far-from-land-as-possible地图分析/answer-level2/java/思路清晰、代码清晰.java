```
public int maxDistance(int[][] grid) {
    int m = grid.length, n = grid[0].length;
    //广度优先遍历
    Queue<int[]> queue = new LinkedList<>();
    boolean[][] visited = new boolean[m][n];
    // 把所有为1的位置加入到队列中
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                queue.add(new int[]{i, j});
                visited[i][j] = true;
            }
        }
    }
    // 如果全是0或者全是1，返回-1
    if (queue.isEmpty() || queue.size() == m * n) return -1;
    int ans = 0;
    while (!queue.isEmpty()) {
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            int[] cur = queue.poll();
            findValidPos(cur[0] + 1, cur[1], visited, queue);
            findValidPos(cur[0] - 1, cur[1], visited, queue);
            findValidPos(cur[0], cur[1] + 1, visited, queue);
            findValidPos(cur[0], cur[1] - 1, visited, queue);
        }
        if (!queue.isEmpty()) ans++;
    }
    return ans;
}

private void findValidPos(int i, int j, boolean[][] visited, Queue<int[]> queue) {
    if (i >= 0 && i < visited.length && j >= 0 && j < visited[0].length && !visited[i][j]) {
        queue.add(new int[] {i ,j});
        visited[i][j] = true;
    }
}
```
