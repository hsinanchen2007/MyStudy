### 解题思路
emmm，没啥好说的，看懂题意就会了

### 代码

```java
class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int[] maxRow = new int[row];
        int[] maxCol = new int[col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                maxRow[i] = Math.max(maxRow[i], grid[i][j]);
                maxCol[j] = Math.max(maxCol[j], grid[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                res += Math.min(maxCol[j], maxRow[i]) - grid[i][j];
            }
        }
        return res;
    }
}
```