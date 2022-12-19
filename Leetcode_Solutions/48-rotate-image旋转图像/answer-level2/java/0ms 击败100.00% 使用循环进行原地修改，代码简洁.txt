### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
      public void rotate(int[][] matrix) {
        int n = matrix.length;
        boolean[][] isRotate = new boolean[n][n];
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (isRotate[r][c]) {
                    continue;
                }
                int curNum = matrix[r][c];
                for (int k = 0; k < 4; k++) {
                    isRotate[r][c] = true;
                    int nr = c;
                    int nc = n - 1 - r;
                    int temp = matrix[nr][nc];
                    matrix[nr][nc] = curNum;
                    curNum = temp;
                    r = nr;
                    c = nc;
                }
            }
        }
    }
}
```