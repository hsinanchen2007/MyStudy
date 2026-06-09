### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int min;

    public Solution() {
        this.min = -1;
    }

    public int orangesRotting(int[][] grid) {
        Queue<Node> q = new LinkedList<>();
        int[] dx = { -1, 0, 1, 0 };
        int[] dy = { 0, 1, 0, -1 };
        boolean hasOrange = false;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 2) {
                    q.add(new Node(i, j));
                }
                if (!hasOrange && grid[i][j] == 1) {
                    hasOrange = true;
                }
            }
        }
        if (hasOrange && q.isEmpty()) {
            return -1;
        }
        if (!hasOrange && q.isEmpty()) {
            return 0;
        }
        while (!q.isEmpty()) {
            int qSize = q.size();
            this.min++;
            while (qSize-- > 0) {
                Node cur = q.poll();
                grid[cur.x][cur.y] = 0;
                for (int j = 0; j < 4; j++) {
                    int curX = cur.x + dx[j];
                    int curY = cur.y + dy[j];
                    if (curX >= 0 && curX < grid.length && curY >= 0 && curY < grid[0].length) {
                        if (grid[curX][curY] == 1) {
                            q.add(new Node(curX, curY));
                            grid[curX][curY] = 2;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return this.min;
    }

    class Node {
        private int x;
        private int y;
        
        public Node(int x,  int y) {
            this.x = x;
            this.y = y; 
        }
    }
}
```