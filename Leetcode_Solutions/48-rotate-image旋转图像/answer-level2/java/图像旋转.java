1. 这道题关键之处在找到每个坐标的旋转位置。
2. 在旋转需要将矩阵分为4个块，可以水平分割，也可以对角线分割。本算法为对角线分割

```Java
class Solution {
    public void rotate(int[][] matrix) {
        
        if (matrix == null || matrix.length == 0 || matrix.length == 1) {
            return;
        }
        
        int row = matrix.length;
        int col = matrix[0].length;
        
        for (int i = 0; i < row / 2; i++) {
            for (int j = i; j < col - i - 1; j++) {
                int top = matrix[i][j];
                matrix[i][j] = matrix[col - j - 1][i];
                matrix[col - j - 1][i] = matrix[col - i - 1][col - j - 1];
                matrix[col - i - 1][col - j - 1] = matrix[j][col - i - 1];
                matrix[j][col - i - 1] = top;
            }
        }
        
    }
}
```