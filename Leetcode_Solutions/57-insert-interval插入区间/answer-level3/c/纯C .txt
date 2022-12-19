### 解题思路
纯C 一步一步做

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define IN 
#define OUT

int** insert(IN int** intervals, IN int intervalsSize, IN int* intervalsColSize, IN int* newInterval, IN int newIntervalSize, OUT int* returnSize, OUT int** returnColumnSizes){
    if (0 == intervalsSize)
    {
        *returnSize = 1;
        int** ppRes1 = (int**)malloc(1 * sizeof(int*));
        ppRes1[0] = (int*)malloc(2 * sizeof(int));
        ppRes1[0][0] = newInterval[0];
        ppRes1[0][1] = newInterval[1];
        *returnColumnSizes = (int*)malloc(1 * sizeof(int));
        *returnSize = 1;
        (*returnColumnSizes)[0] = 2;
        return ppRes1;
    }

    int cur = 0;
    int row = 0;
    int sta = newInterval[0];
    int end = newInterval[1];

    int** ppRes = (int**)malloc((intervalsSize + 1) * sizeof(int*)); // 加一防止最后多出一段
    for (row = 0; row <= intervalsSize; row++)
    {
        ppRes[row] = (int*)malloc(*intervalsColSize * sizeof(int));
    }
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc((intervalsSize + 1) * sizeof(int));

    // 去除前面的
    for (; cur <= intervalsSize - 1; cur++)
    {
        if (intervals[cur][1] >= newInterval[0])
        {
            break;
        }

        ppRes[*returnSize][0] = intervals[cur][0];
        ppRes[*returnSize][1] = intervals[cur][1];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
    }

    if (cur == intervalsSize)
    {
        ppRes[*returnSize][0] = newInterval[0]; // 还好前面加了一
        ppRes[*returnSize][1] = newInterval[1];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
        return ppRes;
    }

    // 得出合并的开头
    sta = intervals[cur][0] < sta ? intervals[cur][0] : sta;

    // 找合并的结尾
    for (; cur <= intervalsSize - 1; cur++)
    {
        if (intervals[cur][0] > newInterval[1])
        {
            break;
        }

        end = intervals[cur][1] > end ? intervals[cur][1] : end;
    }

    ppRes[*returnSize][0] = sta;
    ppRes[*returnSize][1] = end;
    (*returnColumnSizes)[*returnSize] = 2;
    (*returnSize)++;

    // 处理剩余的
    for (; cur <= intervalsSize - 1; cur++)
    {
        ppRes[*returnSize][0] = intervals[cur][0];
        ppRes[*returnSize][1] = intervals[cur][1];
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
    }

    return ppRes;
}
```