### 解题思路
SPFA算法

设置到达某个节点的初始值都是最大值

然后从第一个节点开始优化路径，到达当前节点的上一个节点可能从四个方向来，所以要算出四个路径的最小值
如果优化后的值比原先的值小，则当前节点的下个节点（上下左右四个）都可能优化

使用队列来保存需要优化的节点
### 代码

```java
class Solution {
    public int minCost(int[][] grid) {
        int[][] cost = new int[grid.length][grid[0].length];
        for (int i = 0; i < cost.length; i++) {
            for (int j = 0; j < cost[i].length; j++) {
                cost[i][j] = 10000;
            }
        }
        Queue<int[]> queue = new LinkedList<>(); // 存储需要优化路径的节点
        queue.add(new int[]{0,0});

        int[] location;
        int xIndex, yIndex, preCost, newCost;
        while (!queue.isEmpty()) {
            location = queue.poll();
            xIndex = location[0];
            yIndex = location[1];
            preCost = cost[xIndex][yIndex];
            newCost = getCost(xIndex, yIndex, cost, grid);
            if (newCost < preCost) {
                cost[xIndex][yIndex] = newCost;
                if (xIndex - 1 >= 0) {
                    queue.add(new int[]{xIndex - 1, yIndex});
                }
                if (xIndex + 1 < grid.length) {
                    queue.add(new int[]{xIndex + 1, yIndex});
                }
                if (yIndex - 1 >= 0) {
                    queue.add(new int[]{xIndex, yIndex - 1});
                }
                if (yIndex + 1 < grid[xIndex].length) {
                    queue.add(new int[]{xIndex, yIndex + 1});
                }
            }
        }

        return cost[cost.length - 1][cost[0].length - 1];
    }

    private int getCost(int i, int j, int[][] cost, int[][] grid) {
        if (i == 0 && j == 0) {
            return 0;
        }
        int min = 10000;
        // 从上面一个节点走到当前节点
        if (i > 0) {
            min = Math.min(min, cost[i-1][j] + (grid[i-1][j] == 3? 0 : 1));
        }
        // 从左边一个节点走到当前节点
        if (j > 0) {
            min = Math.min(min, cost[i][j-1] + (grid[i][j-1] == 1? 0 : 1));
        }

        // 从下面面一个节点走到当前节点
        if (i < cost.length - 1) {
            min = Math.min(min, cost[i+1][j] + (grid[i+1][j] == 4? 0 : 1));
        }
        // 从右边一个节点走到当前节点
        if (j < cost[i].length - 1) {
            min = Math.min(min, cost[i][j+1] + (grid[i][j+1] == 2? 0 : 1));
        }
        return min;
    }
}
```