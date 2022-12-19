### 解题思路
if(matrix[i][j] == 0){
    flag_row[i]=1;
    flag_col[j]=1;
}
再把flag是1的row和col置0.
完全不用考虑第几行先后顺序.nice!

### 代码

```c
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){

    int row = matrixSize, col = *matrixColSize;
    int* flag_row = (int*)malloc(sizeof(int) * row);
    int* flag_col = (int*)malloc(sizeof(int) * col);

     for(int i=0; i<row; i++){
         for(int j=0; j<col; j++){
             if(matrix[i][j] == 0){
                 flag_row[i]=1;
                 flag_col[j]=1;
             }
         }
     }

     for(int i=0; i<row; i++){
         if(flag_row[i] == 1){
             for(int j=0; j<col; j++) matrix[i][j]=0;
         }
     }
     for(int i=0; i<col; i++){
         if(flag_col[i] == 1){
             for(int j=0; j<row; j++) matrix[j][i]=0;
         }
     }

     return matrix;
}
```