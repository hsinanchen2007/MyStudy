每一圈作为一个循环，循环的实现由多分支的if-else实现，代码中cycle决定每一个循环的边界。
```c
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize==0){
        *returnSize=0;
        return 0;
    }
    int cycle=0,row=0,column=0,k=0;
    *returnSize=matrixSize*(*matrixColSize);
    int *res=malloc(*returnSize * sizeof(int));
    while(k<*returnSize){
        res[k++]=matrix[row][column];
        if(row==cycle&&(column<*matrixColSize-cycle-1)) column++;
        else if((column==*matrixColSize-cycle-1)&&(row<matrixSize-cycle-1)) row++;
        else if((row==matrixSize-cycle-1)&&column>cycle) column--;
        else if(column==cycle&&(row>cycle+1)) row--;
        else{
            cycle++;
            column++;
        }
    }
    return res;
}
```