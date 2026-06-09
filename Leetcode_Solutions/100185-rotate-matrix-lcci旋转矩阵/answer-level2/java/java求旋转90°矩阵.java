**此题位矩阵求转置之后再将各行交换（不是排序）**
```
class Solution {
    public void rotate(int[][] matrix) {
            //int[][] matrix1 = new int[matrix.length][matrix[0].length];
            //得到转置矩阵
            for(int i = 0;i < matrix.length;i++){
                  for(int j = 0+i;j < matrix.length;j++){//j=0+1防止变换已经完成的元素
                        int tmp = matrix[i][j];
                        matrix[i][j] = matrix[j][i];
                        matrix[j][i] = tmp;

                      //System.out.println( matrix[i][j]);
                  }
            }
             //System.out.println( Arrays.deepToString(matrix));
             //交换转置矩阵的每一行
              for(int i = 0;i < matrix.length;i++){
                   for(int j = 0;j < matrix.length;j++){
                       if(j < (matrix[i].length)/2){
                        int m  = matrix[i][matrix[i].length-1-j];
                        matrix[i][matrix[i].length-1-j] = matrix[i][j];
                        matrix[i][j] = m;
                       }
                    
                  }  
              }
    }
}
```
