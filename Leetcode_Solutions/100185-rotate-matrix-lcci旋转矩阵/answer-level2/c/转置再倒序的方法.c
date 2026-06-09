### 解题思路
此处撰写解题思路

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i,j,temp;
    for(i=0;i<matrixSize;i++){
        for(j=i;j<matrixSize;j++){
            temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
     
        }
    }
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixSize/2;j++){
            temp=matrix[i][j];
            matrix[i][j]=matrix[i][matrixSize-1-j];
            matrix[i][matrixSize-1-j]=temp;
        }
    }
    *matrixColSize=matrixSize;
}
```分两步，第一步将该矩阵转置，第二步每行倒序，即可得到所需矩阵。易证明该结论。
