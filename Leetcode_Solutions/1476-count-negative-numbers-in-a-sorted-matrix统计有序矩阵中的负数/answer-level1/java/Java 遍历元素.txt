### 解题思路
从第一行遍历每个元素，当出现一个元素为负数时，此元素位置的后面及下面的长方形区域都会是负数。
之后便不再需要遍历到此列。

### 代码

```java
class Solution {
    public int countNegatives(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int res = 0;

        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j] <0) {
                    res += (cols-j) * (rows-i);
                    cols = j;
                }
            }
        }
        return res;

    }
}
```