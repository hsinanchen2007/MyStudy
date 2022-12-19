### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int surfaceArea(int[][] grid) {
        int res = 0;
        if (grid == null || grid.length == 0) {
            return res;
        }
        int[] arr1 = {-1, 1, 0, 0};
        int[] arr2 = {0, 0, 1, -1};
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid.length; j++) {
                if (grid[i][j] > 0) {
                    res += (4 * grid[i][j] + 2);//等差数列
                    //查看相邻位置是否有重复
                    for (int x = 0; x < arr1.length; x++) {
                        if (legal(grid, i + arr1[x], j + arr2[x])) {
                            //取重叠最小的高度
                            int lowerHeight = Math.min(grid[i][j], grid[i + arr1[x]][j + arr2[x]]);
                            res -= lowerHeight;//减去多计算的面积,这里不能是 2 * lowerHeight,因为同一个重叠部分会减2次
                        }
                    }
                }
            }
        }
        return res;
    }

    private boolean legal(int[][] grid, int row, int col) {
        return row >= 0 && row < grid.length && col >=0 && col < grid[0].length;
    }

    public static void main(String[] args) {
        System.out.println(new Solution().surfaceArea(new int[][]{{2,2,2},{2,1,2},{2,2,2}}));
    }
}
```