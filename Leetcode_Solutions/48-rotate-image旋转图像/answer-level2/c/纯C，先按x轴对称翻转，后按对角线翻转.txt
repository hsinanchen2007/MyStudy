### 解题思路
方法一：
1,先把矩阵按x轴中间对称翻转
2,在1的基础上按照对角线翻转
### 代码

```c


//方法一：
//1,先把矩阵按x轴中间对称翻转
//2,在1的基础上按照对角线翻转

//函数一：将矩阵按照x轴中间对称翻转
void rotate_x(int** matrix, int matrixSize, int* matrixColSize){
    int     x       = 0;
    int     y       = 0;
    int     iTmp    = 0;

    for (y = 0; y < matrixSize; y++)
    {
        for (x = 0; x < matrixSize / 2; x++)
        {
            iTmp = matrix[x][y];
            matrix[x][y] = matrix[matrixSize - x - 1][y];
            matrix[matrixSize - x - 1][y] = iTmp;
        }
    }

    return;
}

//函数二：将矩阵按照对角线xy对称翻转
void rotate_xy(int** matrix, int matrixSize, int* matrixColSize){
    int     x       = 0;
    int     y       = 0;
    int     iTmp    = 0;

    for (y = 1; y < matrixSize; y++)
    {
        for (x = 0; x < y; x++)
        {
            iTmp = matrix[x][y];
            matrix[x][y] = matrix[y][x];
            matrix[y][x] = iTmp;
        }
    }
    return;
}


void rotate(int** matrix, int matrixSize, int* matrixColSize){

    //1,将矩阵按照x轴中间对称翻转
    rotate_x(matrix, matrixSize, matrixColSize);

    //2,将矩阵按照对角线xy对称翻转
    rotate_xy(matrix, matrixSize, matrixColSize);

    return;
}
```