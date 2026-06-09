### 解题思路
首先采用双重遍历，找到腐烂的橘子和新鲜的橘子，将腐烂的橘子的坐标记录在`queue`中，将新鲜的橘子的数量记录下来，接着进行前置判断，如果全都是腐烂的橘子，或者没有新鲜橘子，依题意可知腐烂只需要0分钟。随后就开始使用广度优先搜索进行上下左右四个方向进行腐烂。并且进行感染数量的统计，最后判断受感染的新鲜橘子的数量是否等于开头新鲜橘子的数量，如果不等于则返回-1，说明有橘子不可能收到感染。

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<int[]> queue = new LinkedList<>();
        int N = grid.length;
        int M = grid[0].length;
        // 总共的新鲜数量
        int freshNumber = 0;
        // 感染新鲜的数量
        int infectedNumber = 0;
        // 找出所有的腐烂橘子
        for (int i=0; i<grid.length; ++i) {
            for (int j=0; j<grid[i].length; ++j) {
                if (grid[i][j] == 2) {
                    queue.add(new int[]{i, j});
                } else if (grid[i][j] == 1) {
                    freshNumber++;
                }
            }
        }

        // 没有新鲜橘子，或者全部都是腐烂橘子
        if (queue.size() == M * N || freshNumber == 0) {
            return 0;
        }

        int minutes = 0;
        while (!queue.isEmpty()) {
            // 记录每一轮扩散
            int currentSize = queue.size();
            for (int i = 0; i < currentSize; ++i) {
                int[] indexs = queue.poll();
                int x = indexs[0];
                int y = indexs[1];
                
                // 腐烂的橘子向上下左右四个方向腐烂
                if (x - 1 >= 0 && grid[x-1][y] == 1) {
                    queue.add(new int[]{x-1, y});
                    grid[x-1][y] = 2;
                    infectedNumber++;
                }

                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    queue.add(new int[]{x, y-1});
                    grid[x][y - 1] = 2;
                    infectedNumber++;
                }

                if (x + 1 < N && grid[x+1][y] == 1) {
                    queue.add(new int[]{x+1, y});
                    grid[x+1][y] = 2;
                    infectedNumber++;
                }

                if (y + 1 < M && grid[x][y + 1] == 1) {
                    queue.add(new int[]{x, y+1});
                    grid[x][y + 1] = 2;
                    infectedNumber++;
                }
                
            }

            minutes++;
        }

        return freshNumber == infectedNumber ? minutes - 1 : -1;
    }
}
```