### 解题思路
将所有的陆地加入队列，然后遍历每一个出列的节点的上下左右，将这一层的节点value赋值为当前层数，如果该节点不是海洋或者已经被赋值则不再更新数值，这样可以确保每一片海洋都是被最近的陆地所访问到，赋值就是最近距离了

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {

        class Node {
            int x; 
            int y;
            int value;
            Node(int i, int j, int value) {
                this.x = i;
                this.y = j;
                this.value = value;
            }
        }

        Queue<Node> q = new LinkedList<>();
        int row = grid.length;
        int col = grid[0].length;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    Node n = new Node(i, j, 0);
                    q.offer(n);
                }
            }
        }
        int res = -1;
        while (!q.isEmpty()) {
            Node n = q.poll();
            int x = n.x;
            int y = n.y;
            int value = n.value;
            if (x - 1 != -1 && grid[x - 1][y] == 0) {
                grid[x - 1][y] = value + 1;
                q.offer(new Node(x - 1, y, value + 1));
                res = Math.max(res, value + 1);
            }
            if (x + 1 < row && grid[x + 1][y] == 0) {
                grid[x + 1][y] = value + 1;
                q.offer(new Node(x + 1, y, value + 1));
                res = Math.max(res, value + 1);
            }
            if (y - 1 != -1 && grid[x][y - 1] == 0) {
                grid[x][y - 1] = value + 1;
                q.offer(new Node(x, y - 1, value + 1));
                res = Math.max(res, value + 1);
            }
            if (y + 1 < col && grid[x][y + 1] == 0) {
                grid[x][y + 1] = value + 1;
                q.offer(new Node(x, y + 1, value + 1));
                res = Math.max(res, value + 1);
            }
        }
        return res;
    }
}
```