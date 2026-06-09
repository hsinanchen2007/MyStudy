dfs剪枝

```java
class Solution {
    public int max = 0;
    public int mMax = -999999;
    public int longestIncreasingPath(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j ++) {
                if (mMax < matrix[i][j]) mMax = matrix[i][j];
            }
        }
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j ++) {
                if (mMax - matrix[i][j] + 1 > max) {
                    dfs(i, j, matrix, 1);
                }
            }
        }
        return max;
    }

    public void dfs(int i, int j, int[][] matrix, int len) {
        if (max < len) max = len;
        int current = matrix[i][j];
        if (mMax - current + len > max) {
            if (i - 1 >= 0 && current < matrix[i - 1][j]) {
                dfs(i - 1, j, matrix, len + 1);
            }
            if (i + 1 < matrix.length && current < matrix[i + 1][j]) {
                dfs(i + 1, j, matrix, len + 1);
            }
            if (j + 1 < matrix[0].length && current < matrix[i][j + 1]) {
                dfs(i, j + 1, matrix, len + 1);
            }
            if (j - 1 >= 0 && current < matrix[i][j - 1]) {
                dfs(i, j - 1, matrix, len + 1);
            }
        }
    }
    
}
```