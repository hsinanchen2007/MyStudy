### 解题思路
根据题意，遍历该二维数组累加每个位置上正方体的表面积，定义direction记录该位置的四个方向，若在该位置的四个方向上有相邻的正方体，需要将相邻之间的重叠的表面积减去。

### 代码

```java
class Solution {
      public int surfaceArea(int[][] grid) {
        int[][] direction = {{-1,0},{1,0},{0, -1},{0, 1}};
        int m = grid.length;  // 行
        int n = grid[0].length; // 列
        int area = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int value = grid[i][j];
                if(value != 0) area += value*4 + 2;
                for (int k = 0; k < 4; k++) {
                    int x = i + direction[k][0];
                    int y = j + direction[k][1];
                    if(x >= 0 && x < m && y >= 0 && y < n) {
                        area -= Math.min(grid[x][y], value);
                    }
                }
            }
        }
        return area;
    }
}
```