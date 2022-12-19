![捕获.PNG](https://pic.leetcode-cn.com/f44be7315cd31602a4c623a635ba0ad3a171e0e2ea667e501d27db300a113dc5-%E6%8D%95%E8%8E%B7.PNG)

从右上方的元素开始对比target和矩阵，如果相等则返回true；如果traget大，则行加1，target小则列加1

bool findNumberIn2DArray(int** matrix, int matrixSize, int *matrixColSize, int target){
    int i,j;

    if ( (matrix == (void *)0) || (0 >= matrixSize) || (1 > *matrixColSize) )
    {
        return false;
    }

    for (i = 0, j = (*matrixColSize - 1); ((i < matrixSize) && (j  >= 0));) 
    {
        if (target == matrix[i][j])
            return true;
        else if (target < matrix[i][j])
            j--;
        else
            i++;
    }

    return false;
}