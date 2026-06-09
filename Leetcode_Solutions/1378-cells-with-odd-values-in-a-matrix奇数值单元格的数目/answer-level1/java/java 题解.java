### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int oddCells(int n, int m, int[][] indices) {
        int [][] puzzle = new int[n][m];
        int count  = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                puzzle[i][j] = 0;
            }
        }
        for (int i = 0; i < indices.length; i++) {
            int ri = indices[i][0];
            int ci = indices[i][1];
            // 对行加1
            int j = 0;
            for (j = 0; j < m; j++) {
                puzzle[ri][j] += 1;
            }
            // 对列加1
            for (j = 0; j < n; j++) {
                puzzle[j][ci] += 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (puzzle[i][j] % 2 == 1) {
                    count++;
                }
            }
        }
        return count;
    }
}
```