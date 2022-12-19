### 解题思路
xy面只需要值大于0则面积加1，其他两个面则分别求每行最大值的累加值和每列最大值的累加值即可，可以通过两次遍历得到.

### 代码

```java
class Solution {
    public int projectionArea(int[][] grid) {
        int len = grid.length;
        int a = 0;
        int b = 0;
        int c = 0;
        for (int i = 0; i < len; i++) {
            int max = 0;
            for (int j = 0; j < len; j++) {
                int v = grid[i][j];
                max = Math.max(max, v);
                if (v > 0) {
                    c++;
                }
            }
            a += max;
        }
        for (int i = 0; i < len; i++) {
            int max = 0;
            for (int j = 0; j < len; j++) {
                int v = grid[j][i];
                max = Math.max(max, v);
            }
            b += max;
        }
        return a + b + c;
    }
}
```