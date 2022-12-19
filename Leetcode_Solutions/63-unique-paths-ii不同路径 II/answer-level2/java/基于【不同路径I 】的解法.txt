```java
class Solution {
    // 向下或者向右移动一步，障碍物的地方为 0；
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int R = obstacleGrid.length;
        int C = obstacleGrid[0].length;
        int[] cur = new int[C];
        // 我们先初始化下默认的行；
        for (int j = 0; j < C; ++j) {
            if (obstacleGrid[0][j] == 1) { // 有障碍物，为 0；
                cur[j] = 0;
            } else if (obstacleGrid[0][j] == 0 && j > 0 && cur[j - 1] == 0) { // 无障碍物，但是前面为 0；
                cur[j] = 0; // 无法达到；
            } else {
                cur[j] = 1; // 可以达到；
            }
        }
        for (int i = 1; i < R; ++i) {
            // 注意这里要从 0 开始；
            for (int j = 0; j < C; ++j) {
                // 是障碍物，每一行都可能是障碍物，所以要动态调整；
                if (obstacleGrid[i][j] == 1) {
                    cur[j] = 0;
                    continue;
                }
                // 依然和 【不同路径I 】的优化方案一样的；
                if (j > 0) {
                    cur[j] += cur[j - 1];
                }
            }
        }
        return cur[C - 1];
    }
}
```
