### 解题思路
1.grid中每个元素为单位计算
2.上、下、左、右、前、后分别计算累加

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int rtn = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                int v = grid[i][j];
                //如果格子上没有元素
                if (v <= 0) {
                    continue;
                }
                //上,下,肯定有,并且是1
                rtn += 2;
                //左,如果是第一组,左边就是立方体的数量
                if (i == 0) {
                    rtn += v;
                } else {
                    rtn += v > grid[i - 1][j] ? v - grid[i - 1][j] : 0;
                }
                //右
                if (i == grid.length - 1) {
                    rtn += v;
                } else {
                    rtn += v - grid[i + 1][j] > 0 ? v - grid[i + 1][j] : 0;
                }
                //前
                if (j == 0) {
                    rtn += v;
                } else {
                    rtn += v - grid[i][j - 1] > 0 ? v - grid[i][j - 1] : 0;
                }
                //后
                if (j == grid[i].length - 1) {
                    rtn += v;
                } else {
                    rtn += v - grid[i][j + 1] > 0 ? v - grid[i][j + 1] : 0;
                }

            }
        }
        return rtn;
    }
}
```