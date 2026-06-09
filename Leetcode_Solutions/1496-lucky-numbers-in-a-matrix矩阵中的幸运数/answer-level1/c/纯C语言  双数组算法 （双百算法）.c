用了两个数组 一个用于找到每一行的最小值  一个用于不断更改找到每一列的最大值
最后两个数组进行查找相同的数放在要返回的数组中，over
有一些注释因为我当时不明白题意，加的调试（两个小时，害）
```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *luckyNumbers(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    int col_num = matrixColSize[0];
    //printf("%d\n",matrix[0][3]);
    //printf("%d\n",col_num);
    //printf("%d\n",matrixSize);
    int col_array[matrixSize], c = 0, row_array[col_num], r = 0;//col_num是一行有多少个数 matrixSize是一共有多少行
    memset(row_array, 0, sizeof(int) * col_num);
    int col_min = INT_MAX;
    int row_num = 0;
    int u = 0;
    int *return_array = (int *)malloc(sizeof(int) * matrixSize);
    for (int i = 0; i < matrixSize; i++)
    {
        //printf("%d",c);
        col_min = INT_MAX;
        for (int j = 0; j < col_num; j++)
        {
            if (matrix[i][j] > row_array[j])//从每一行的每一列中找到最大值
                row_array[j] = matrix[i][j];
            if (matrix[i][j] < col_min)
                col_min = matrix[i][j];
            //printf("%8d  %10d\n",matrix[0][j],j);
        }
        col_array[c++] = col_min;
    }
    for (int e = 0; e < matrixSize; e++)  //col_array是每一行的最小值
    {
        
        for (int ee = 0; ee < col_num; ee++)
        {
            //printf("%d\n",row_array[ee]);
            //printf("%4d\n",col_array[e]);
            if (row_array[ee] == col_array[e])
            {
                return_array[u] = col_array[e];
                u++;
                //printf("%9d %2d\n",return_array[u-1],u-1);
                break;
            }
        }
    }
    //printf("%5d",u);
    *returnSize = u;
    return return_array;
}
```
