### 解题思路
感觉题目不严谨，没有说每个数组的长度是相同的，我是按照不相同来做的，用hash表存储结果计算

### 代码

```java
class Solution {
    public int projectionArea(int[][] grid) {
        int[] xs = new int[50];
        int[] ys = new int[50];
        int area = 0;

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 0) continue;
                xs[i] = Math.max(xs[i], grid[i][j]);
                ys[j] = Math.max(ys[j], grid[i][j]);
                area++;
            }
        }

        for (int i = 0; i < xs.length; i++) area += xs[i] + ys[i];

        return area;
    }
}
```