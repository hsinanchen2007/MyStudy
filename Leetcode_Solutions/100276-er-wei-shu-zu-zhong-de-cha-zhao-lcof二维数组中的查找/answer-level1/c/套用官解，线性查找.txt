 

### 代码

```c
 bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
     int row=0;
     int col=*matrixColSize-1;
     if(matrixSize==0||*matrixColSize==0)
         return false;
     while(row<matrixSize&&col>=0){
         if(target>matrix[row][col]){
             row++;
         }else if(target<matrix[row][col]){
             col--;
         }else if(target==matrix[row][col]){
             return true;
         }
     }
     return false;
}
```