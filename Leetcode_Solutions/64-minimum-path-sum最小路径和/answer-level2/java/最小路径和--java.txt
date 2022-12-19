### 解题思路
1、暴力解法----含递归
2、动态规划
a、从左上角开始
b、从右下角开始

3、其他
1）二维数组的初始化
int[][] newGrid = new int[grid.length][grid[0].length];
int[][] newGrid = new int[1][];
int[][] newGrid = {{1，2，3}，{1，2}};
2）求最大最小值
Math.min()
Math.max()
3)获得int的最大最小值，一般用于求最大最小值时，标记不可能走的路径
Integer.MAX_VALUE
Integer.MIN_VALUE
Integer.MIN_VALUE = Integer.MAX_VALUE+1

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        int[][] newGrid = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (i == 0 && j == 0) {
                    newGrid[i][j] = grid[i][j];
                } else if (i == 0 && j >= 1) {
                    newGrid[i][j] = grid[i][j] + newGrid[i][j - 1];
                } else if (j == 0 && i >= 1) {
                    newGrid[i][j] = grid[i][j] + newGrid[i - 1][j];
                } else {
                    newGrid[i][j] = grid[i][j] + Math.min(newGrid[i][j - 1], newGrid[i - 1][j]);
                }
            }
        }
        return newGrid[grid.length-1][grid[0].length-1];
    }
}
```