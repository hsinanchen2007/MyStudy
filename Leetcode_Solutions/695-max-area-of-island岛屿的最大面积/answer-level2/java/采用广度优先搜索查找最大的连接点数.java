### 解题思路
 采用广度优先搜索查找最大的连接点数:
  遍历矩阵中的每一个元素:
    1).将元素坐标添加到队列
    2).从队列中消费依此元素，直到为空退出循环
    3).如果该坐标元素值为1，则连接点计数加一，并将该位置的值置为0
    4).后将其上下左右(有的话)元素坐标依此添加到队列

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }

        int maxCount = 0;

        //队列用来存储当前结点能广度到达的所有结点，其中的元素为二维数组，表示每个结点的横纵坐标
        Queue<int[]> queue = new LinkedList<>();

        int xLength = grid.length;
        int yLength = grid[0].length;
        for (int x = 0; x < xLength; x++) {
            for (int y = 0; y < yLength; y++) {
                if (x < 0 || y < 0 || x > xLength || y > yLength || grid[x][y] != 1) {
                    continue;
                }

                int curCount = 1;
                grid[x][y] = 0;
                queue.add(new int[]{x, y});
                while (!queue.isEmpty()) {
                    int[] curIndexs = queue.poll();
                    int curX = curIndexs[0];
                    int curY = curIndexs[1];

                    grid[curX][curY] = 0;

                    if (curX - 1 >= 0 && grid[curX - 1][curY] == 1) {//上
                        grid[curX - 1][curY] = 0;
                        curCount++;
                        queue.add(new int[]{curX - 1, curY});
                    }

                    if (curX + 1 < xLength && grid[curX + 1][curY] == 1) {//下
                        grid[curX + 1][curY] = 0;
                        curCount++;
                        queue.add(new int[]{curX + 1, curY});
                    }

                    if (curY - 1 >= 0 && grid[curX][curY - 1] == 1) {//左
                        grid[curX][curY - 1] = 0;
                        curCount++;
                        queue.add(new int[]{curX, curY - 1});
                    }

                    if (curY + 1 < yLength && grid[curX][curY + 1] == 1) {//右
                        grid[curX][curY + 1] = 0;
                        curCount++;
                        queue.add(new int[]{curX, curY + 1});
                    }

                }

                maxCount = Math.max(maxCount, curCount);
            }
        }

        return maxCount;
    }
}
```