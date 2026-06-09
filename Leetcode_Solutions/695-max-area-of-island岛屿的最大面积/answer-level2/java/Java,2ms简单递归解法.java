### 解题思路
先遍历grid[][],找到等于1的元素;
再对这个元素周围元素进行递归搜索...
详细过程见注释.

### 代码

```java
class Solution {

    //递归函数
     public int findAround(int[][] grid, int i, int j) {

        //终止递归的条件
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == 0)
            return 0;
        else {
            grid[i][j] = 0;//防止重复记录
            return 1 + findAround(grid, i - 1, j)
                    + findAround(grid, i + 1, j)
                    + findAround(grid, i, j - 1)
                    + findAround(grid, i, j + 1);

        }
    }

    public int maxAreaOfIsland(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int res = 0;

        //遍历grid[][]
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //获取最大值
                res = Math.max(res, findAround(grid, i, j));
            }
        }

        return res;

    }
}
```