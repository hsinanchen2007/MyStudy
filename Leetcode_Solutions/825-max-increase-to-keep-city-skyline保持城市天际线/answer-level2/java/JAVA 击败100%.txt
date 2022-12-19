1.将二维数组整体扫描一遍，更新每个单位所在行，所在列的最大值
2.再次将二维数组扫描一遍，比较当前单位与所在行所在列的最大值，各自取差，较小值就为每个单位可以添加的高度
```
class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int[] rows = new int[grid.length];
        int[] cols = new int[grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] > rows[i]) rows[i] = grid[i][j];
                if (grid[i][j] > cols[j]) cols[j] = grid[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                res += Math.min(rows[i] - grid[i][j], cols[j] - grid[i][j]);
            }
        }
        return res;
    }
}
```
