没看到有人用c写，就附一个出来。
```
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int i= 0 ,j = 0;
    if (matrixRowSize == 0 ||matrixColSize == 0){
        return false;
    }
    if (target > matrix[matrixRowSize - 1][matrixColSize - 1] ||target < matrix[0][0]){
        return false;
    }
    //从左下角开始搜索
    while (i < matrixRowSize && j < matrixColSize){
        if (matrix[matrixRowSize - 1 - i][j] ==target ){
            return true;
        }else if (matrix[matrixRowSize - 1 - i][j] > target){
            i++;
        }else{
            j++;
        }
    }
    return false;
}
```
