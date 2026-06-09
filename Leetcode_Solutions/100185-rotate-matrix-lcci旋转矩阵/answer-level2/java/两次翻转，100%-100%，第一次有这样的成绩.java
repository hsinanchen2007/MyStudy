### 解题思路
第一次翻转：按照主对角线翻转数据
第二次翻转：按照列对称轴翻转数据
内在的数学运算我还没写出来。。。


### 代码

```java
class Solution {
    
    public void rotate(int[][] matrix) {
        
        int rows = matrix.length, cols = matrix[0].length;
        
        // 按照主对角线翻转数据
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix, i, j, j, i);
            }
        }
        
        // 按照列对称轴翻转数据
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols - 1 - j; j++) {
                swap(matrix, i, j, i, cols - 1 - j);
            }
        }
    }
    
    private void swap(int[][] matrix, int i , int j, int m, int n) {
        
        int t = matrix[i][j];
        matrix[i][j] = matrix[m][n];
        matrix[m][n] = t;
    }
}
```