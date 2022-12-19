### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int N = 0;
    public int maxDistance(int[][] grid) {
        if (grid == null || grid.length <= 0) {
            return -1;
        }

        N = grid.length;

        Queue<NodeCoordinate> queue = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    queue.offer(new NodeCoordinate(i, j));
                }
            }
        }
        if (queue.size() == 0 || queue.size() == N * N) {
            return -1;
        }

        int distance = -1;
        while (!queue.isEmpty()) {
            distance++;
            int queueSize = queue.size();
            for (int i = 0; i < queueSize; i++) {
                NodeCoordinate curNode = queue.poll();
                List<NodeCoordinate> ocens = getAroundOcean(curNode, grid);
                if (!ocens.isEmpty()) {
                    queue.addAll(ocens);
                }
            }
        }

        return distance;

    }

    private List<NodeCoordinate> getAroundOcean(NodeCoordinate curNode, int[][] grid) {
        List<NodeCoordinate> oceans = new ArrayList<>();
        int row = curNode.x;
        int col = curNode.y;
        // 向上
        if (row > 0 && grid[row - 1][col] == 0) {
            oceans.add(new NodeCoordinate(row - 1, col));
            grid[row - 1][col] = 2;
        }

        //向下
        if (row < N - 1 && grid[row + 1][col] == 0) {
            oceans.add(new NodeCoordinate(row + 1, col));
            grid[row + 1][col] = 2;
        }

        //向左
        if (col > 0 && grid[row][col - 1] == 0) {
            oceans.add(new NodeCoordinate(row, col - 1));
            grid[row][col - 1] = 2;
        }

        //向右
        if (col < N - 1 && grid[row][col + 1] == 0) {
            oceans.add(new NodeCoordinate(row, col + 1));
            grid[row][col + 1] = 2;
        }

        return oceans;
    }

    class NodeCoordinate {
        int x;

        int y;

        public NodeCoordinate(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
```