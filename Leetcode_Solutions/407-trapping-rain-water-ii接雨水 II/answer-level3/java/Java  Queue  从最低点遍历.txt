### 解题思路
Cell 是 数据结构，保存了每个点的横纵坐标和高度
1. 建立一个priorityQueue
2. 先把边上的点全部入Queue
3. 然后一点点向内渗透
具体见代码
### 代码

```java
class Solution {
    int[] dirs = {0, 1, 0, -1, 0};
    public int trapRainWater(int[][] heightMap) {
        int res = 0;
        if (heightMap == null || heightMap[0].length == 0 || heightMap.length == 0) return 0;
        PriorityQueue<Cell> pq = new PriorityQueue<>((a, b) -> (a.height - b.height));
        int n = heightMap.length;
        int m = heightMap[0].length;
        boolean[][] visit = new boolean[n][m];
        for (int i = 0; i < n; i ++) {
            visit[i][0] = true;
            visit[i][m - 1] = true;
            pq.add(new Cell(i, 0, heightMap[i][0]));
            pq.add(new Cell(i, m - 1, heightMap[i][m - 1]));
        }

        for (int j = 0; j < m; j ++) {
            visit[0][j] = true;
            visit[n - 1][j] = true;
            pq.add(new Cell(0, j, heightMap[0][j]));
            pq.add(new Cell(n - 1, j, heightMap[n - 1][j]));
        }
        while (!pq.isEmpty()) {
            Cell top = pq.poll();
            int x = top.row;
            int y = top.column;
            int height = top.height;
            for (int i = 0; i < 4; i ++) {
                int dx = x + dirs[i];
                int dy = y + dirs[i + 1];
                if (dx < 0 || dx >= n || dy < 0 || dy >= m || visit[dx][dy]) continue;
                visit[dx][dy] = true;
                res += Math.max(0, height - heightMap[dx][dy]);
                pq.add(new Cell(dx, dy, Math.max(height, heightMap[dx][dy])));
            }
        }
        return res;
    }
    public class Cell {
        int row;
        int column;
        int height;
        public Cell(int row, int column, int height) {
            this.row = row;
            this.column = column;
            this.height = height;
        }
    }
}


```