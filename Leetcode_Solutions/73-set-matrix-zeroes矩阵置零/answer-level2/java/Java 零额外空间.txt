```
class Solution {
    public void setZeroes(int[][] matrix) {
            if(matrix == null || matrix.length == 0){
                return;
            }
            for(int i = 0;i < matrix.length;i++){
                for(int j = 0;j < matrix[0].length;j++){
                    if(matrix[i][j] == 0){
                        setZeroesHelp(matrix, i, j);
                    }
                }
            }
            for(int i = 0;i < matrix.length;i++){
                for(int j = 0;j < matrix[0].length;j++){
                    if(matrix[i][j] == 9999){
                        matrix[i][j] = 0;
                    }
                }
            }

    }

    public void setZeroesHelp(int[][] matrix,int r,int c){
        if(matrix == null || matrix.length == 0){
            return;
        }
        for(int i = 0;i < matrix[0].length;i++){
            if(matrix[r][i] != 0){
                matrix[r][i] = 9999;
            }
            
        }
        for(int i = 0;i < matrix.length;i++){
            if(matrix[i][c] != 0){
                matrix[i][c] = 9999;
            }
        }
    }

}
```
