

### 代码

```java
class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int xLength = grid[0].length;//数组的宽度
        int yLength = grid.length;//数组的高度

        if (grid[0][0] == 1 || grid[yLength - 1][xLength - 1] == 1) {
            return -1;
        }
        //八个方向
        int[][] dir = new int[][]{{1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
        int minPath = Integer.MAX_VALUE;//最短路径
        //维护BFS队列
        Queue<Node> nodeQueue = new ArrayDeque<>();
        //维护路径长度队列，与 nodeQueue同进同出
        Queue<Integer> pathQueue = new ArrayDeque<>();

        nodeQueue.offer(new Node(grid[0][0],0,0));
        //被放进队列的点标记为不可达
        grid[0][0] = 1;
        pathQueue.offer(1);
        while (nodeQueue.peek() != null) {
            Node node = nodeQueue.poll();
            Integer path = pathQueue.poll();
            //到达终点
            if (node.x == xLength - 1 && node.y == yLength - 1) {
                minPath = Math.min(minPath, path);
                continue;
            }
            //不是终点，找下一个点
            for (int i = 0; i < 8; i++) {
                int nextX = node.x + dir[i][0];
                int nextY = node.y + dir[i][1];
                //下一个点在范围内，且值为0
                if (0 <= nextX && nextX < xLength && 0 <= nextY && nextY < yLength && grid[nextY][nextX] == 0) {
                    //放进BFS队列，同时更新路径队列、点的状态
                    nodeQueue.offer(new Node(grid[nextY][nextX], nextX, nextY));
                    grid[nextY][nextX] = 1;
                    pathQueue.offer(path + 1);
                }
            }
        }
        return minPath == Integer.MAX_VALUE ? -1 : minPath;
    }
}

class Node {
    int val;
    int x;
    int y;

    public Node(int val, int x, int y) {
        this.val = val;
        this.x = x;
        this.y = y;
    }
}
```