### 解题思路
遍历二位数组
  1.若此单元格上小方块数不为0，则则总面积增加4*n+2个单元面积。
  2.判断右侧邻居是否存在，存在减去与右侧重合部分的面积，去掉的面积为两个单元格中数量少的方块数*2
  3.判断下方邻居是否存在，存在减去与下方重合部分的面积，去掉的面积为两个单元格中数量少的方块数*2
### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {

        int result = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {

                //如果方块数为0，则不会增加总面积
                if (grid[i][j] == 0) {
                    continue;
                }
                //增加面积数为方块数*4+2
                result += 4 * (grid[i][j]) + 2;
                //如果右侧存在
                if (j + 1 < grid[i].length) {
                    //减去右侧相邻的面积数    
                    result -= Math.min(grid[i][j], grid[i][j + 1]) * 2;
                }
                //如果下放存在
                if(i+1< grid.length){
                    //减去下方相邻的面积数
                    result -= Math.min(grid[i+1][j], grid[i][j]) * 2;

                }

            }
        }
        return result;

    }
}
```