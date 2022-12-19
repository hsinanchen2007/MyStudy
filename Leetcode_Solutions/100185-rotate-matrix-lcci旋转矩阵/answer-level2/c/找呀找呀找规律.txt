### 解题思路
找规律
a[0][1]    --->  a[1][0]
a[1][0]    --->  a[2][1]
a[2][1]    --->  a[1][2]
a[1][2]    --->  a[0][1]

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i, j;
    int temp;
    int n = matrixSize;

    for (i=0 ; i<(n+1)/2; i++)
    {
        for(j=0 ; j<n/2; j++)
        {
            temp = matrix[i][j];
            matrix[i][j]   = matrix[n-j-1][i];
            matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
            matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
            matrix[j][n-i-1]   = temp;
        }
    }

    return matrix;

}
```