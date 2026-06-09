```
//转移前后的区别 转移前：i j 转制后：j col-1-i

class Solution {
    public void rotate(int[][] matrix) {
        int row = matrix.length;
        int col = matrix[0].length;
        int[][] tem = new int[row][col];
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                tem[j][col-i-1] = matrix[i][j];
            }
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                matrix[i][j] = tem[i][j];
            }
        }
    }
}
```
