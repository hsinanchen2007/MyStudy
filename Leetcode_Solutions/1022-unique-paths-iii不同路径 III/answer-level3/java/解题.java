### 解题思路
求解这张图的所有哈密尔顿路径即可

### 代码

```java
class Solution {
        private int hamiltonPathCount;
        private int startX;
        private int startY;
        private int endX;
        private int endY;
        private boolean[][] visited;
        private int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        private int[][] grid;
        private int unblockedSize;

        public int uniquePathsIII(int[][] grid) {
            if (grid == null || grid.length == 0 || grid[0].length == 0)
                return 0;
            this.grid = grid;
            visited = new boolean[grid.length][grid[0].length];
            for (int i = 0; i < grid.length; i++)
                for (int j = 0; j < grid[i].length; j++) {
                    int currentValue = grid[i][j];
                    if (currentValue == 0)
                        unblockedSize++;
                    else if (currentValue == 1) {
                        startX = i;
                        startY = j;
                    } else if (currentValue == 2) {
                        endX = i;
                        endY = j;
                    }
                }
            // 递归第一次会多减去一个1，所以要多加一个1
            unblockedSize++;
            findHamiltonPath(startX, startY);
            return hamiltonPathCount;
        }

        private void findHamiltonPath(int startX, int startY) {
            visited[startX][startY] = true;
            unblockedSize--;
            for (int i = 0; i < dirs.length; i++) {
                int nextX = startX + dirs[i][0];
                int nextY = startY + dirs[i][1];
                if (nextX == endX && nextY == endY && unblockedSize == 0) {
                    hamiltonPathCount++;
                    continue;
                }
                if (inArea(nextX, nextY) && !visited[nextX][nextY] && grid[nextX][nextY] == 0)
                    findHamiltonPath(nextX, nextY);
            }
            unblockedSize++;
            visited[startX][startY] = false;
        }

        private boolean inArea(int x, int y) {
            return x >= 0 && x < grid.length && y >= 0 && y < grid[0].length;
        }
    }
```