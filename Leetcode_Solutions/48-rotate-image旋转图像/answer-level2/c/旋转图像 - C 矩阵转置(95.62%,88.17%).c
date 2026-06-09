看见这种旋转，自然而然地想到了矩阵的转置（行列互换）
![QQ截图20200128215202.png](https://pic.leetcode-cn.com/bc90fa2572d7d0fbe7120e00afe7376feb934c90266b81b88a5d547205f7f1e8-QQ%E6%88%AA%E5%9B%BE20200128215202.png)
```
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int temp;
    int i,j;
    for (i = 0; i < matrixSize; ++i)
        for (j = 0; j < matrixSize; ++j)
        {
            if(i<=j)
                break;
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }

    int index;
    for (i = 0; i < matrixSize; ++i)
    {
        index  = matrixSize-1;
        for (j = 0; j < matrixSize/2; ++j)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][index];
            matrix[i][index--] = temp;
        }
    }
}
```
