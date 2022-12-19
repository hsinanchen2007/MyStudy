### 解题思路
纯C 深度优先 回溯 递归

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 500

static int compare(const int* a, const int* b)
{
    return *(int*)a - *(int*)b;
}

static void dfs(int* candidates, int candidatesSize, int target,
                int* returnSize, int** returnColumnSizes,
                int** ppRes, int* pBuffer, bool* pbUsed, 
                int indexOfCan, int indexOfBuf)
{
    int index = 0;

    if (0 == target)
    {
        ppRes[*returnSize] = (int*)malloc(indexOfBuf * sizeof(int));
        memcpy(ppRes[*returnSize], pBuffer, indexOfBuf * sizeof(int));
        (*returnColumnSizes)[*returnSize] = indexOfBuf;
        (*returnSize)++;
    }
    else if (0 < target)
    {
        for (index = indexOfCan; index <= candidatesSize - 1; index++)
        {
            if (false == pbUsed[index])
            {
                if (indexOfCan != index && candidates[index - 1] == candidates[index] && false == pbUsed[index])
                {
                    continue;
                }

                pbUsed[index] = true;

                pBuffer[indexOfBuf] = candidates[index];

                dfs(candidates, candidatesSize, target - candidates[index],
                    returnSize, returnColumnSizes,
                    ppRes, pBuffer, pbUsed,
                    index + 1, indexOfBuf + 1); // 因为不重复，所以从下一个开始（indexOfCan + 1）

                pbUsed[index] = false;
            }
        }
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target,
                      int* returnSize, int** returnColumnSizes)
{
    qsort(candidates, candidatesSize, sizeof(int), compare);

    int indexOfCan = 0;
    int indexOfBuf = 0;

    int** ppRes = (int**)malloc(MAX_SIZE * sizeof(int*));
    int* pBuffer = (int*)malloc(target * sizeof(int));
    bool* pbUsed = (bool*)malloc(candidatesSize);
    memset(pbUsed, false, candidatesSize);

    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(MAX_SIZE * sizeof(int));

    dfs(candidates, candidatesSize, target,
        returnSize, returnColumnSizes,
        ppRes, pBuffer, pbUsed,
        indexOfCan, indexOfBuf);

    return ppRes;
}
```