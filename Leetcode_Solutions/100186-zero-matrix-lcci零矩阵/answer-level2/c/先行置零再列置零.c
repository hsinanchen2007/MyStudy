### 解题思路
首先定义flag判断第0行是否有0，之后从第1行遍历，遇到0则将matrix[0][j]置零，并将标志zero置一表示该行有零，遍历玩该行后根据zero置零该行。
最后将第0行的每个0对应的列置零，在根据flag判断是否将第0行置零。

### 代码

```c
void init0(int** matrix,int i,int col)
{
    for(int k=0;k<col;k++)
    {
        matrix[i][k]=0;
    }
}
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int row = matrixSize,col = *matrixColSize;
    int zero=0,flag=0;
    for(int j=0;j<col;j++)
    {
        if(matrix[0][j]==0)
            flag = 1;
    }
    for(int i=1;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(matrix[i][j]==0)
            {
                 matrix[0][j]=0;
                 zero = 1;
            }
        }
        if(zero)
            init0(matrix,i,col);
        zero =0;
    }
    for(int j=0;j<col;j++)
    {
        if(matrix[0][j]==0)
            for(int r=0;r<row;r++)
                matrix[r][j]=0;
    }
    if(flag)
        init0(matrix,0,col);
    return matrix;
}
```