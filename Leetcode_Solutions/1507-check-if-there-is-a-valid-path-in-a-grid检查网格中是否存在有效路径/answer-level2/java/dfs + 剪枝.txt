### 解题思路
应该还可以优化

每个方向都有特定的三条路可以走
![image.png](https://pic.leetcode-cn.com/4e4852c6fc242ad9f3c2d74ab06b1ec5e0d2b0aea8774b5d1ec386e98c4011f5-image.png)
![image.png](https://pic.leetcode-cn.com/b14073d9719e9bb3eaad4de9736ceb8eb6595222ca2af49a5b46c4317c9609d2-image.png)
![image.png](https://pic.leetcode-cn.com/5185f6b251a268e3d6ca2bfd5368d516a4308bef2016085dc625d3d4b270c01c-image.png)
![image.png](https://pic.leetcode-cn.com/2a1c3a5d9fb9bd184710a5586d83b21decf2911555125371461b51442baae457-image.png)

### 代码

```java
class Solution {
    public boolean hasValidPath(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        boolean[][] isVisited = new boolean[m][n];
        return dfs(grid, isVisited, m, n, 0, 0, 0);
    }

    private boolean dfs(
            int[][] grid, boolean[][] isVisited, int m, int n, int i, int j, int expect) {
        if (i < 0 || i > m - 1 || j < 0 || j > n - 1 // 超出范围
                || isVisited[i][j] // 已经走过
                || !isExpect(grid[i][j], expect)) // 此路不通
            return false;
        if (i == m - 1 && j == n - 1) return true; // 到达终点
        isVisited[i][j] = true; // 记录状态
        switch (grid[i][j]) {
            case 1:
                return dfs(grid, isVisited, m, n, i, j - 1, 3) // 左
                        || dfs(grid, isVisited, m, n, i, j + 1, 4); // 右
            case 2:
                return dfs(grid, isVisited, m, n, i - 1, j, 1) // 上
                        || dfs(grid, isVisited, m, n, i + 1, j, 2); // 下
            case 3:
                return dfs(grid, isVisited, m, n, i, j - 1, 3) // 左
                        || dfs(grid, isVisited, m, n, i + 1, j, 2); // 下
            case 4:
                return dfs(grid, isVisited, m, n, i, j + 1, 4) // 右
                        || dfs(grid, isVisited, m, n, i + 1, j, 2); // 下
            case 5:
                return dfs(grid, isVisited, m, n, i, j - 1, 3) // 左
                        || dfs(grid, isVisited, m, n, i - 1, j, 1); // 上
            case 6:
                return dfs(grid, isVisited, m, n, i, j + 1, 4) // 右
                        || dfs(grid, isVisited, m, n, i - 1, j, 1); // 上
            default:
                return false;
        }
    }

    // 对比街道val是否满足可以从dir方向到来的前提
    private boolean isExpect(int val, int dir) {
        if (dir == 0) return true; // 如果是0，代表是(0,0)，不用管
        if (dir == 1) return val == 2 || val == 3 || val == 4; // 上
        if (dir == 2) return val == 2 || val == 5 || val == 6; // 下
        if (dir == 3) return val == 1 || val == 4 || val == 6; // 左
        if (dir == 4) return val == 1 || val == 3 || val == 5; // 右
        return false;
    }
}
```