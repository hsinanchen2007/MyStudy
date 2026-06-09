### 解题思路
找到格子相互重复的个数 。格子相互重复的情况 在同一个放个内上下重复。不同排之间前后重复，不同列之间左右重复。
而且重复的永远时每一格中最小的数量。
在遍历时每次都按照上述情况统计重复面和个数就可以。然后用总的面积减去重复的面积j即结果。

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        // 统计有多少个格子
        int num = 0;
        // 统计格子之间挨着的面
        int cover = 0;
        for (int i=0;i<grid.length;i++) {
            for (int j=0;j<grid[i].length;j++) {
                // 计算总过有多少个格子
                num += grid[i][j];
                if (grid[i][j] > 1) {
                    // 计算每一个单元格上竖着的挨着的面
                    cover += grid[i][j] - 1;
                }
                if (i>0) {
                    // 计算当前横向的和前一排横向挨着的面
                    cover += Math.min(grid[i-1][j],grid[i][j]);
                }
                if (j > 0) {
                    // 计算当前竖向的和前一列竖向挨着的面
                    cover += Math.min(grid[i][j-1], grid[i][j]);
                }
            }
        }
        return num*6 - cover*2;
    }
}
```