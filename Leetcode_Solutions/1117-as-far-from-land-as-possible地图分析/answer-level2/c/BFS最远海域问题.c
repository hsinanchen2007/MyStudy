### 解题思路
仍然有一些自己的小疑惑

### 代码

```c
int maxDistance(int** grid, int gridSize, int* gridColSize){
    int k = 2; // 填海代数
	int flag = 0;
	do {
		flag = 0;
		for (int i = 0; i < gridSize; i++) 
        {
			for (int j = 0; j < *gridColSize; j++) 
            {
				if (grid[i][j] == (k - 1)) {
					// 上
					if (i > 0 && grid[i - 1][j] == 0) {
						grid[i - 1][j] = k;
						flag = 1;
					}
					// 下
					if (i < gridSize - 1 && grid[i + 1][j] == 0) {
						grid[i + 1][j] = k;
						flag = 1;
					}
					// 左
					if (j > 0 && grid[i][j - 1] == 0) {
						grid[i][j - 1] = k;
						flag = 1;
					}
					// 右
					if (j < *gridColSize - 1 && grid[i][j + 1] == 0) {
						grid[i][j + 1] = k;
						flag = 1;
					}
				}
			}
		}
		if (flag)
			k++;
	} while (flag);
	return	k == 2 ? -1 : k - 2;
}
```

JAVA实现 （摘自 雪姨）
/*
class Solution {

    public int maxDistance(int[][] grid) {
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        Queue<int[]> queue = new ArrayDeque<>();
        int m = grid.length, n = grid[0].length;
        // 先把所有的陆地都入队。
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
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
            // 取出队列的元素，将其四周的海洋入队。
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] != 0) {
                    continue;
                }
                grid[newX][newY] = grid[x][y] + 1; // 这里我直接修改了原数组，因此就不需要额外的数组来标志是否访问
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