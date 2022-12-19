### 解题思路
思路很简单就是先对矩阵做转置，然后对称。

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int n = matrixSize;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for(i=0;i<n;i++)
    {
        int left = 0;
        int right = n-1;
        while(left<right)
        {
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] =temp;
            left++;
            right--;
        }
    }
}
```