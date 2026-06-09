### 解题思路
原矩阵第一列从下往上就是新矩阵第一行的结果，以此类推。

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int* nums=(int*)malloc(sizeof(int)*(matrixSize*matrixSize));
    int k=0;
    for(int i=0;i<matrixSize;i++)
    {
        for(int j=matrixSize-1;j>=0;j--)
        {
            nums[k++]=matrix[j][i];
        }
    }
    int t=0;
    for(int i=0;i<matrixSize;i++)
    {
        for(int j=0;j<matrixSize;j++)
        {
            matrix[i][j]=nums[t++];
        }
    }
    *matrixColSize=matrixSize;
}
```