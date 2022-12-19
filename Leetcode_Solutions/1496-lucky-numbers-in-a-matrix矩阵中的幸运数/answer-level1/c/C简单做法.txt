### 解题思路
此处撰写解题思路

### 代码
注释详细，易理解
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int *res = (int *)malloc(sizeof(int) * matrixSize *matrixColSize[0]);
    int i,minj,min,j,k,index = 0;                                           //min记录当前行最小值，minj记录此最小值得列号，index记录返回数组得下标
    int flag = 0;                                                           //表示min是否为所求点
    for(i = 0;i < matrixSize;i++)
    {
        min = matrix[i][0];                                                 //假设i行1列为最小值
        minj = 0;
        for(j = 0;j < matrixColSize[i];j++)
        {
            if(matrix[i][j] < min)                                          //找出i行最小值
            {
                min = matrix[i][j];                                         //记录最小值
                minj = j;                                                   //记录列号
            }
        }
        flag = 1;                                                           //假设该点行最小列最大
        for(k = 0;k < matrixSize;k++)                                       //检查是否列最大
        {
            if(min < matrix[k][minj])                                       
            {
                flag = 0;                                                   //不符合，则继续外循环
                continue;
            }
        }
        if(flag)
        {
            res[index++] = min;                                             //符合题意放入res数组
        }
    }
    *returnSize = index;
    return res;
}
```