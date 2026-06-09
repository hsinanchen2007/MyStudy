![image.png](https://pic.leetcode-cn.com/ae344e518b26d34dc7fad4d94173047dcea801ad121f73f35e1803c409a64fcb-image.png)
    **这道题其实即使一个dfs的题目，我们可以先定个思路：如果当前点为1，那么就需要在这个点的基础上进行dfs（也就是上下左右四个点进行dfs），同时把当前这个点标记为已经访问过了（我是将grid[i][j]标记为-1），从而避免下次重复访问；如果当前点为0，那么跳过它（因为即使它周围有1，但也不能通过它来连接到）。最后每次递归出口前需要比较下与全局变量maxArea的大小，看是否是最终答案。**
    
```
class Solution {
    int maxArea = 0;

    public int maxAreaOfIsland(int[][] grid) {
        if (grid.length == 0) {
            return maxArea;
        }
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = -1;
                    dfs(grid, i, j, 1);
                }
            }
        }
        return maxArea;
    }

    public int dfs(int[][] grid, int i, int j, int current) {
        int up = 0, down = 0, left = 0, right = 0;
        if (i >= 1 && grid[i - 1][j] == 1) {
            grid[i - 1][j] = -1;
            up = dfs(grid, i - 1, j, 1);
        }
        if (i <= grid.length - 2 && grid[i + 1][j] == 1) {
            grid[i + 1][j] = -1;
            down = dfs(grid, i + 1, j, 1);
        }
        if (j >= 1 && grid[i][j - 1] == 1) {
            grid[i][j - 1] = -1;
            left = dfs(grid, i, j - 1, 1);
        }
        if (j <= grid[0].length - 2 && grid[i][j + 1] == 1) {
            grid[i][j + 1] = -1;
            right = dfs(grid, i, j + 1, 1);
        }
        int maxCurrent = up + down + left + right + current;
        maxArea = Math.max(maxArea, maxCurrent);
        return maxCurrent;
    }
}
```
