### 解题思路

### 代码

解法一：虚拟值暴力解法（不好，负虚拟值难以确定）
```java
class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        if(m == 0) return;
        int n = matrix[0].length;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    for(int a = 0; a < m; a++) 
                        if(matrix[a][j] != 0) matrix[a][j] = -100000;
                    for(int b = 0; b < n; b++) 
                        if(matrix[i][b] != 0) matrix[i][b] = -100000;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == -100000) matrix[i][j] = 0;
            }
        }
    }
}
```
解法二：标记
```java
class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        if(m == 0) return;
        int n = matrix[0].length;
        boolean mark = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                mark = true;
                break;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if(matrix[0][0] == 0) 
            for(int i = 0; i < n; i++) 
                matrix[0][i] = 0;
        if(mark)
            for(int i = 0; i < m; i++) 
                matrix[i][0] = 0;
    }
}
```