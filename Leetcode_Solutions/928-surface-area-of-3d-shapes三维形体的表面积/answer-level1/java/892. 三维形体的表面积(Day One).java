### 解题思路
每次遇到立方体就计算面积：
1 计算当前立方体面积
2 减去重复计算的右边部分
3 减去重复计算的左边部分

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int N = grid.length;
        int area = 0;
        int temp;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                temp = grid[i][j];
                if (0 == temp) {
                    continue;
                }

                //先计算当前的面积
                area += temp * 6 - (temp - 1) * 2;
                //减掉重复计算的面积
                if (j + 1 < N) {//right
                    if (0 != grid[i][j + 1]) {
                        area -= Math.min(temp, grid[i][j + 1]) * 2;
                    }
                }
                //减掉重复计算的面积
                if (i + 1 < N) {//bottom
                    if (0 != grid[i + 1][j]) {
                        area -= Math.min(temp, grid[i + 1][j]) * 2;
                    }
                }
            }
        }

        return area;
    }
}
```