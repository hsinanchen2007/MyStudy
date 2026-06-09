### 解题思路
此题算比较经典的题，还是回溯的思想，此题和#79的那个题一模一样。

注意点：
要注意审题，从中获取有用判断条件。不然有可能会有遗漏的条件，造成不能100%通过

总结：
时间和空间复杂度都不太理想，😁

### 代码

```java
class Solution {
    public int getMaximumGold(int[][] grid) {
        int max = 0;
        boolean [][] used = new boolean[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                int curNum = getResult(grid, used, grid.length, grid[0].length, i,j, 0);
                if (curNum > max) {
                    max = curNum;
                }
            }
        }
        return max;
    }
    public int getResult(int[][] grid, boolean[][] used, int x, int y, int curX, int curY, int num) {
        if (curX < 0 || curX >= x || curY < 0 || curY >= y || grid[curX][curY] == 0) {
            return num;
        }
        int max = 0;
        if (!used[curX][curY] && grid[curX][curY] != 0) {
            used[curX][curY] = true;
            int down = getResult(grid, used,x, y, curX+1, curY, num + grid[curX][curY]);
            int up = getResult(grid, used,x, y, curX-1, curY, num + grid[curX][curY]);
            int left = getResult(grid, used,x, y, curX, curY-1, num + grid[curX][curY]);
            int right = getResult(grid, used,x, y, curX, curY+1, num + grid[curX][curY]);
            max = Math.max(Math.max(Math.max(down, up), left),right);
            used[curX][curY] = false;
        }
        return max;
    }
}
```