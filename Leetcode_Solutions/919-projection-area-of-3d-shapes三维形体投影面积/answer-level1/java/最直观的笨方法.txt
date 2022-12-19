最直观的笨方法就是获取到顶面、左面和前面这三个面的面积然后累加，当一个块后面的块比当前块高时，再继续累加两个块高度差值。

```java
class Solution {
    /* 投影法，从顶面、前面和左面来考虑。顶面只要存在的位置都为1进行累加，前面和左面需要对相应高度进行累加，还需考虑后面大于它的需要累加 */
    public int projectionArea(int[][] grid) {
        int rows = grid.length;
        if (rows == 0) {
            return 0;
        }
        int cols = grid[0].length;
        // 首先获取顶面的面积
        int res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res += grid[i][j] == 0 ? 0 : 1;
            }
        }
        // 获取左面的面积
        for (int i = 0; i < rows; i++) {
            int cur = grid[i][0];
            res += cur;
            // 考虑后面的面积
            for (int j = 1; j < cols; j++) {
                if (grid[i][j] > cur) {
                    res += grid[i][j] - cur;
                    cur = grid[i][j];
                }
            }
        }
        // 获取前面的面积
        for (int j = 0; j < cols; j++) {
            int cur = grid[0][j];
            res += cur;
            // 考虑后面的面积
            for (int i = 1; i < rows; i++) {
                if (grid[i][j] > cur) {
                    res += grid[i][j] - cur;
                    cur = grid[i][j];
                }
            }
        }
        return res;
    }
}
```
