```
/**
     * 多源广度优先思路 (BFS: 类似于水波纹一层一层往外扩散)
     * 1. 找到已经腐烂多橘子，放在一个队列中，作为第一层腐烂的橘子
     * 2. 开始对橘子进行腐化演进，并将上一层的橘子腐化，如果当前橘子前后左右有需要继续腐化的，入队，作为下一次腐化
     * 3. 记录腐化层级
     * 4. 判断是否全部腐化，如果还有未腐化的，返回-1
     */
    public int orangesRotting(int[][] grid) {
        int[] dx = new int[]{-1, 1, 0, 0};
        int[] dy = new int[]{0, 0, -1, 1};
        // 腐化层次计数器
        int count = 0;
        if (null == grid) return count;
        Queue<int[][]> queue = new LinkedList<>();
        // 找出已经腐化演进的橘子(第0次腐化)
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 2) queue.add(new int[][]{{i, j}});
            }
        }
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                int[][] currentNode = queue.poll();
                for (int k = 0; k < dx.length; k++) {
                    int x = currentNode[0][0] + dx[k], y = currentNode[0][1] + dy[k];
                    if (x >= 0 && y >= 0 && x < grid.length && y < grid[0].length) {
                        if (grid[x][y] == 1) {
                            grid[x][y] = 2;
                            queue.add(new int[][]{{x, y}});
                        }
                    }
                }
            }
            // 如果本层次的腐化完成之后，没有橘子需要再下一步的腐化，则不记录计数器
            if (!queue.isEmpty()) {
                count++;
            }
        }
        // 判断是否全部腐化，如果还有未腐化的，返回-1
        for (int i = 0; i < grid.length; i++) {
            for (int v : grid[i]) {
                if (v == 1) return -1;
            }
        }
        return count;
    }
```
