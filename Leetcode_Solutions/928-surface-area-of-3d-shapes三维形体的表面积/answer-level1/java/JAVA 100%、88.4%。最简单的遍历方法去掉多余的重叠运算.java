首先计算出当前柱体的总面积（不考虑与周围柱体之间的重叠），
然后以当前柱体为中心计算右侧与上侧的重叠面积，使用总面积减去此面积，
按照这种方式遍历NxN网格的所有位置。由于遍历时从最左上角开始，
所以最终计算的重叠面积是包含所有柱体的重叠面积（即不会重复计算两次同一处的重叠）。
按这种思路计算最终得到的结果即为最终面积。
```
package leetCodeTest;

public class 三维形体的表面积 {
    /**
     * 首先计算出当前柱体的总面积（不考虑与周围柱体之间的重叠），
     * 然后以当前柱体为中心计算右侧与上侧的重叠面积，使用总面积减去此面积，
     * 按照这种方式遍历NxN网格的所有位置。由于遍历时从最左上角开始，
     * 所以最终计算的重叠面积是包含所有柱体的重叠面积（即不会重复计算两次同一处的重叠）。
     * 按这种思路计算最终得到的结果即为最终面积。
     * @param grid
     * @return
     */
    public int surfaceArea(int[][] grid) {
        int i,j;
        int count=0;
        for (i=0;i<grid.length;i++){
            for (j=0;j<grid[i].length;j++){
                if (grid[i][j] != 0){
                    count += (grid[i][j]-1)*4 + 6;
                    int res = find(i, j, grid);
                    count -= res;
                }
            }
        }
        return count;
    }
    public int find(int i,int j,int[][] grid){
        if (grid[i][j] == 0)
            return 0;
        int count = 0;
        if (i-1 >=0 && grid[i-1][j] != 0)
            count += Math.min(grid[i][j], grid[i-1][j])*2;
        if (j - 1 >= 0 && grid[i][j-1] != 0)
            count += Math.min(grid[i][j],grid[i][j-1])*2;
        return count;
    }
}

```
