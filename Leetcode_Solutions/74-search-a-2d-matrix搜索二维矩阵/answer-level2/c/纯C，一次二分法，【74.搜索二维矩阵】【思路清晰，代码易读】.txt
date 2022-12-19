### 解题思路
方法一：两次二分法
1,第一次二分法找到行
2,第二次二分法找到列

方法二：一次二分法
1, 将 m*n 矩阵看做是(m*n - 1)一维的有序数组
2, Mid 位置对应的数组下标 matrix[Mid / Col][Mid % Col]

### 代码

```c
//方法二：一次二分法
//1, 将 m*n 矩阵看做是(m*n - 1)一维的有序数组
//2, Mid 位置对应的数组下标 matrix[Mid / Col][Mid % Col]
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int     iRow        = matrixSize;
    int     iCol        = matrixColSize[0];
    int     iMat_L      = 0;
    int     iMat_R      = iRow * iCol - 1;
    int     iMat_M      = 0;
    int     iMat        = 0;

    if ((NULL == matrix) || (0 == matrixSize)) return false;

    while (iMat_L <= iMat_R)
    {
        iMat_M = (iMat_L + iMat_R) / 2;
        iMat = matrix[iMat_M / iCol][iMat_M % iCol];

        if (iMat == target)
        {
            return true;
        }
        else if (iMat < target)
        {
            iMat_L = iMat_M + 1;
        }
        else 
        {
            iMat_R = iMat_M - 1;
        }
    }

    return false;
}

/*
//方法一：两次二分法
//1,第一次二分法找到行
//2,第二次二分法找到列
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int     iRow        = matrixSize;
    int     iCol        = matrixColSize[0];
    int     iRow_L      = 0;
    int     iRow_R      = iRow - 1;
    int     iRow_M      = (iRow_L + iRow_R) / 2;
    int     iCol_L      = 0;
    int     iCol_R      = iCol - 1;
    int     iCol_M      = (iCol_L + iCol_R) / 2;

    if ((NULL == matrix) || (0 == matrixSize)) return false;

    //1，第一次二分法，找到行
    while(iRow_L < iRow_R)
    {
//        printf("[1][RL=%d][RM=%d][RR=%d]\n", iRow_L, iRow_M, iRow_R);
        iRow_M = (iRow_L + iRow_R + 1) / 2;
        if (matrix[iRow_M][0] == target)
        {
            return true;
        }
        else if (matrix[iRow_M][0] < target)
        {
            iRow_L = iRow_M;
        }
        else 
        {
            iRow_R = iRow_M - 1;
        }
    }

    //2,第二次二分法，在 iCol_L 行中找目标值
    while(iCol_L <= iCol_R)
    {
//        printf("[2][CL=%d][CM=%d][CR=%d]\n", iRow_L, iRow_M, iRow_R);
        iCol_M = (iCol_L + iCol_R) / 2;
        if (matrix[iRow_L][iCol_M] == target)
        {
            return true;
        }
        else if (matrix[iRow_L][iCol_M] < target)
        {
            iCol_L = iCol_M + 1;
        }
        else 
        {
            iCol_R = iCol_M - 1;
        }
    }

    return false;
}
*/
```