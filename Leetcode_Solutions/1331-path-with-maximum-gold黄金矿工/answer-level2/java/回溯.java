### 解题思路
1.开始节点未知，遍历所有顶点作为开始节点；
2.从各节点开始深度遍历+回溯，在每个节点都取最大的子路径往上返回。

### 代码

```java
class Solution {
    private int max = 0;

    public int getMaximumGold(int[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] != 0) {
                    max = Math.max(max, backTrack(i, j, grid));
                }
            }
        }
        return max;
    }

    private int backTrack(int i, int j, int[][] grid) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length) {
            return 0;
        }

        if (grid[i][j] == 0) {
            return 0;
        }

        int currentCount = grid[i][j];
        grid[i][j] = 0;

        int left = backTrack(i - 1, j, grid);
        int right = backTrack(i + 1, j, grid);
        int up = backTrack(i, j - 1, grid);
        int down = backTrack(i, j + 1, grid);

        grid[i][j] = currentCount;

        return currentCount + Math.max(Math.max(left, right), Math.max(up, down));
    }
}
```