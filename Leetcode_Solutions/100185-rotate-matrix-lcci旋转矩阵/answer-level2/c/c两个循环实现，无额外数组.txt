### 解题思路
直接转置再对称就可以实现旋转90度

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
for(int i=0;i<matrixSize;i++)
    for(int j=0;j<i;j++)
    {
        int temp;
        temp = matrix[i][j];
        matrix[i][j]=matrix[j][i];
        matrix[j][i]=temp;
    }
    for(int i=0;i<matrixSize;i++)
        for(int j=0;j<matrixSize/2;j++)
        {
        int temp;
        temp = matrix[i][j];
        matrix[i][j]=matrix[i][matrixSize-j-1];
        matrix[i][matrixSize-j-1]=temp;
        }
}
```