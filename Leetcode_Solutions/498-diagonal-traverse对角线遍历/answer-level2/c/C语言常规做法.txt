当横纵下标之和为偶数时，遍历方向为左下到右上，为奇数时相反。再对四种情况进行合并，不需要写四个分支,以横纵下标之和为奇数时为例。
```c
if(row==matrixSize-1) column++;
else{
    row++;
    if(column) column--;
}
```
另外需要注意当输入为空时，以下语句将出现执行错误。
```c
*returnSize=matrixSize*(*matrixColSize);
```
需要写成
```c
if(matrixSize==0){
    *returnSize=0;
    return 0;
}
```
完整代码如下。
```c
int* findDiagonalOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize==0){
        *returnSize=0;
        return 0;
    }
    int row=0,column=0,k=0;
    *returnSize=matrixSize*(*matrixColSize);
    int* res=malloc(*returnSize * sizeof(int));
    while(k<*returnSize){
        res[k]=matrix[row][column];
        if((row+column)%2){
            if(row==matrixSize-1) column++;
            else{
                row++;
                if(column) column--;
            }
        }
        else{
            if(column==*matrixColSize-1) row++;
            else{
                column++;
                if(row) row--;
            }
        }
        k++;
    }
    return res;
}
```