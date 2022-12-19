### 解题思路
深度优先 回溯

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define PARAM_OUT
#define PARAM_IN
#define MAX_SIZE_ROW 6000

static void dfs(PARAM_IN int* nums, PARAM_IN int numsSize, PARAM_IN int* buffer,
                PARAM_IN int indexOfStart, PARAM_IN int lengthOfSets,
                PARAM_OUT int** ppResult,
                PARAM_OUT int* returnSize, PARAM_OUT int** returnColumnSizes)
{
    int indexOfNums = 0;

    ppResult[*returnSize] = (int*)malloc(lengthOfSets * sizeof(int));
    memcpy(ppResult[*returnSize], buffer, lengthOfSets * sizeof(int));
    (*returnColumnSizes)[*returnSize] = lengthOfSets;
    (*returnSize)++;

    for (indexOfNums = indexOfStart; indexOfNums <= numsSize - 1; indexOfNums++)
    {
        buffer[lengthOfSets] = nums[indexOfNums];
        
        dfs(nums, numsSize, buffer, indexOfNums+1, lengthOfSets+1, ppResult, returnSize, returnColumnSizes);
    }
}

int** subsets(PARAM_IN int* nums, PARAM_IN int numsSize,
              PARAM_OUT int* returnSize, PARAM_OUT int** returnColumnSizes){
    int** ppResult = (int**)malloc(MAX_SIZE_ROW * sizeof(int*));
    int* buffer = (int*)malloc(numsSize * sizeof(int));

    *returnColumnSizes = (int*)malloc(MAX_SIZE_ROW * sizeof(int));
    *returnSize = 0;

    dfs(nums, numsSize, buffer, 0, 0, ppResult, returnSize, returnColumnSizes);

    return ppResult;
}


```