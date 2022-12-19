```c []
#define RESULT_UNIQUE_NUM 300000

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int i = 0;
    int preRowId;

    int preEndRowId = 0;
    int rowNum = 0;
    int preColumnNum = 0;
    int columnNum;
    int **resultData = (int **)malloc(RESULT_UNIQUE_NUM * sizeof(int *));
    returnColumnSizes[0] = (int *)malloc(RESULT_UNIQUE_NUM * sizeof(int));

    /* 输出空子集 */
    resultData[rowNum] = (int *)malloc(1 * sizeof(int));
    returnColumnSizes[0][rowNum] = 0;
    rowNum++;

    for (i = 0; i < numsSize; i++) {
        /* 本行对应的列数 */
        returnColumnSizes[0][rowNum] = 1;

        resultData[rowNum] = (int *)malloc(1 * sizeof(int));
        resultData[rowNum][0] = nums[i];
        rowNum++;
        for (preRowId = 1; preRowId < preEndRowId; preRowId++) {
            preColumnNum = returnColumnSizes[0][preRowId];
            columnNum = preColumnNum + 1;

            returnColumnSizes[0][rowNum] = columnNum;

            resultData[rowNum] = (int *)malloc(columnNum * sizeof(int));

            resultData[rowNum][0] = nums[i];
            memcpy(&resultData[rowNum][1], resultData[preRowId], preColumnNum * sizeof(int));
            (rowNum)++;
        }
        preEndRowId = rowNum;
    }
    *returnSize = rowNum;
    return resultData;
}
```