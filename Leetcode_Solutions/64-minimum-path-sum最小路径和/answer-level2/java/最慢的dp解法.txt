### 解题思路
dp思路解题，时空复杂度都高，需要改进一下

### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }
        int[][] p = new int[grid.length][grid[0].length];

        for (int i=0;i<grid.length;i++) {
            for (int j=0;j<grid[0].length;j++) {
                if (i == 0) {
                    if (j == 0) {
                        p[i][j] = grid[i][j];
                    } else {
                        p[i][j] = p[i][j-1] + grid[i][j];
                    }
                    continue;
                }
                if (j == 0) {
                    p[i][j] = p[i-1][j] + grid[i][j];
                    continue;
                }
                p[i][j] = Math.min(p[i-1][j], p[i][j-1]) + grid[i][j];
            }
        }
        return p[grid.length-1][grid[0].length-1];
    }
}
```