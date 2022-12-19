### 解题思路
a.遍历每个点，对值为1的地方做dfs(递归)，计算以该店为中心的岛屿数为多少；
b.当处理过一个点，就把该点的值置为0，这样下次遍历到这个点就不会重新再做步骤a了;
c.遍历每个点时，当遇到该点的岛屿和大于当前最大值时，则更新最大值；

### 代码

```java
class Solution {
    public int maxAreaOfIsland(int[][] grid) {
        int maxRow = grid.length;
        int maxCol = grid[0].length;

        int ans = 0;
        for (int i=0;i<maxRow;i++) {
            for (int j=0;j<maxCol;j++) {
                int curAns = dfs(grid,i,j);
                if (curAns > ans) {
                    ans = curAns;
                }
            }
        }
        return ans;
    }

    public int dfs(int[][] grid, int row, int col) {
        if (row < 0 || col <0 || row >=grid.length || col >=grid[0].length) {
            return 0;
        }
        if (grid[row][col] == 0) {
            return 0;
        }
        grid[row][col] = 0;
        int ans = 1;
        ans += dfs(grid, row + 1, col);
        ans += dfs(grid, row - 1, col);
        ans += dfs(grid, row, col + 1);
        ans += dfs(grid, row, col - 1);
        return ans;
    }
}
```