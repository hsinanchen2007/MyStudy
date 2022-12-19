### 解题思路
深度优先 回溯 递归 
定义静态变量执行回溯

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 5000

static int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

static void dfs(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, 
                int** ppRes, bool* pbUsed, int* pBuffer)
{
    static int length = 0;
    int index = 0;

    if (numsSize == length)
    {
        ppRes[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        memcpy(ppRes[*returnSize], pBuffer, numsSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
    }
    else
    {
        for (index = 0; index <= numsSize - 1; index++)
        {
            if (false == pbUsed[index])
            {
                if (index > 0 && nums[index - 1] == nums[index] && true == pbUsed[index - 1]) 
                {
                    continue; // 这里条件换成false == pbUsed[index - 1]也成立，本质是定一个规则这次找还是下次找
                }

                pbUsed[index] = true;
                pBuffer[length] = nums[index];
                length++;

                dfs(nums, numsSize, returnSize, returnColumnSizes, ppRes, pbUsed, pBuffer);
                
                length--; // 回溯
                pbUsed[index] = false;
            } 
        }
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), compare);

    int** ppRes = (int**)malloc(MAX_SIZE * sizeof(int*));
    bool* pbUsed = (bool*)malloc(numsSize * sizeof(bool));
    memset(pbUsed, false, numsSize);
    int* pBuffer = (int*)malloc(numsSize * sizeof(int));

    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(MAX_SIZE * sizeof(int));

    dfs(nums, numsSize, returnSize, returnColumnSizes, ppRes, pbUsed, pBuffer);

    return ppRes;
}
```