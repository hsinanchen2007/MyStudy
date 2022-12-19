### 解题思路
方法一：
1,数组row[]标记行变0，col[]记录列变0

方法二：不使用额外的空间
1,遍历一遍矩阵 如果 matrix[m][n]==0 则将 matrix[0][n]=matrix[m][0]=0
2,第二遍历矩阵，将被标记的行和列置0
### 代码

```c
//方法二：不使用额外的空间
//1,遍历一遍矩阵 如果 matrix[m][n]==0 则将 matrix[0][n]=matrix[m][0]=0
//2,第二遍历矩阵，将被标记的行和列置0
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int     i       = 0;
    int     j       = 0;
    int     iRow    = matrixSize;
    int     iCol    = matrixColSize[0];
    int     iRFlag  = 0;
    int     iCFlag  = 0;   

    //第一次遍历 如果 matrix[m][n]==0 则将 matrix[0][n]=matrix[m][0]=0
    for (i = 0; i < iRow; i++)
    {
        for (j = 0; j < iCol; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;

                if (i == 0)
                {
                    iRFlag = 1;
                }
                if (j == 0)
                {
                    iCFlag = 1;
                }
            }
            
        }
    }

    //第二次遍历，将被标记的行和列置0
    for (i = 1; i < iRow; i++)
    {
        for (j = 1; j < iCol; j++)
        {
            if (matrix[i][0] == 0)
            {
                matrix[i][j] = 0;
            }
            if (matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    //第0行的处理
    if (iRFlag)
    {
        for (j = 0; j < iCol; j++)
        {
            matrix[0][j] = 0;
        }
    }

    //第0列的处理
    if (iCFlag)
    {
        for (i = 0; i < iRow; i++)
        {
            matrix[i][0] = 0;
        }
    }
    return;
}

/*
//方法一：
//1,数组row[]标记行变0，col[]记录列变0
void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int     i           = 0;
    int     j           = 0;
    int     iRow        = matrixSize;
    int     iCol        = matrixColSize[0];
    int     row[iRow];
    int     col[iCol];

    memset(row, 0x00, sizeof(int) * iRow);
    memset(col, 0x00, sizeof(int) * iCol);

    //1,遍历一遍，找出所有为0的元素，并在行，列数组中标记
    for (i = 0; i < iRow; i++)
    {
        for (j = 0; j < iCol; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    //2,遍历数组，按照行，列中的结果修改矩阵
    for (i = 0; i < iRow; i++)
    {
        for (j = 0; j < iCol; j++)
        {
            if (row[i] == 1)
            {
                matrix[i][j] = 0;
            }
            if (col[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
    return;
}
*/
```