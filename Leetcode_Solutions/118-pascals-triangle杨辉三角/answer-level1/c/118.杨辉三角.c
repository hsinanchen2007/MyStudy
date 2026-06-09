### 解题思路
对returnColumnSizes这个参数作讨论：
1)首先觉得这个参数没必要，其次就算实在需要返回列数，貌似一级指针就够了，不过这个参数不赋值测试就是不能通过。
2)这题无非就是考察边界，以及二级指针和二维数组的使用。
3)时间复杂度为O(n^2)。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){

    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(numRows*sizeof(int));    //定义数组指针，其实自我感觉returnColumnSizes只需要定义为一级指针
    int** result = (int**)malloc(numRows*sizeof(int*));     //定义二级指针
    int i = 0, j = 0;

    for(i = 0; i < numRows; i++)
    {
        returnColumnSizes[0][i] = i+1;
        result[i] = (int*)malloc(returnColumnSizes[0][i]*sizeof(int));

        for(j = 0; j < (i+1); j++)
        {
            if((j == 0)||(j == i))
            {
                result[i][j] = 1;
            }
            else
            {
                result[i][j] = result[i-1][j-1]+result[i-1][j];
            }
        }
    }
    return result;
}
```