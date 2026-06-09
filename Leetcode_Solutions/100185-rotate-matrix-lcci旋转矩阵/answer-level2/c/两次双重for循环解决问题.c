### 解题思路
两次双重for循环解决问题
### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int temp;
    for(int i=0;i<matrixSize;i++){//以主对角线作为对称轴，将两边的数字进行转换
        for(int j=i+1;j<matrixSize;j++){
            temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }
    for(int i=0;i<matrixSize;i++){//将同一行的顺序进行调整，得到答案
        for(int j=0;j<(matrixSize/2);j++){
            temp=matrix[i][j];
            matrix[i][j]=matrix[i][matrixSize-j-1];
            matrix[i][matrixSize-j-1]=temp;
        }
    }
}
```