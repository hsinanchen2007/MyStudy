注意，可以不加标志位去判断是否遍历过，加了会导致超时（每次遍历一次，都得清掉标志位）
```
class Solution {
    int[] dx = {-1, 0, 1, 0};
    int[] dy = {0, 1, 0, -1};

    public int[][] updateMatrix(int[][] matrix) {
        int r = matrix.length;
        int c = matrix[0].length;
        int[][] ret = new int[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                bfs(matrix, ret, i, j);
            }
        }
        return ret;
    }

    public void bfs(int[][] matrix, int[][] ret, int x, int y) {
        int r = matrix.length;
        int c = matrix[0].length;
        Queue<Node> queue = new LinkedList<>();
        queue.offer(new Node(x, y, 0));
        while (!queue.isEmpty()) {
            Node top = queue.poll();
            if (matrix[top.x][top.y] == 0) {
                ret[x][y] = top.depth; // 为0，则直接返回depth
                break;
            } else {
                for (int i = 0; i < 4; i++) {
                    int newX = top.x + dx[i];
                    int newY = top.y + dy[i];
                    if (newX < 0 || newX >= r || newY < 0 || newY >= c) {
                        continue;
                    }
                    queue.offer(new Node(newX, newY, top.depth + 1)); // 遍历所求结点的外围结点
                }
            }
        }
    }

    static class Node {
        int x;
        int y;
        int depth;
        Node(int x, int y, int depth) {
            this.x = x;
            this.y = y;
            this.depth = depth; // 保存当前结点与所求结点的深度
        }
    }
}
```
