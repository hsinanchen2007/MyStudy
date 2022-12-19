### 解题思路
先计算当前元素贡献的表面积，然后再减去相邻的两个元素重合的部分

时间复杂度为 O(N*N)
空间复杂度为O(1)


**执行结果：**
执行用时 :4 ms, 在所有 Java 提交中击败了74.18%的用户
内存消耗 :40.8 MB, 在所有 Java 提交中击败了91.91%的用户

### 代码

```java
class Solution {
    /**
     * 先计算当前元素贡献的表面积，然后再减去相邻的两个元素重合的部分
     * 时间复杂度为 O(N*N)
     * 空间复杂度为O(1)
     *
     * @param grid
     * @return
     */
    public int surfaceArea(int[][] grid) {
        int area = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] > 0) {
                    // 获取当前这个元素贡献的表面积，4 个侧面积和 2 个顶面和地面
                    area += grid[i][j] * 4 + 2;
                    // 减去和 grid[i-1][j] 重合的面积
                    if (i > 0) {
                        area -= Math.min(grid[i - 1][j], grid[i][j]) * 2;
                    }
                    // 减去和 grid[i][j-1] 重合的面积
                    if (j > 0) {
                        area -= Math.min(grid[i][j - 1], grid[i][j]) * 2;
                    }
                }
            }
        }
        return area;
    }
}
```