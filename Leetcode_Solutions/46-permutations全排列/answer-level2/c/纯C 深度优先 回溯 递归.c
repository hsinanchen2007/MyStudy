### 解题思路
深度优先 回溯

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 5000

static void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void dfs(int* nums, int numsSize, int* returnSize, int** returnColumnSizes,
                int** ppRes)
{
    static int slow = 0;
    int fast = 0;

    if (slow == numsSize)
    {
        ppRes[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        memcpy(ppRes[*returnSize], nums, numsSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
    }
    else 
    {
        for (fast = slow; fast <= numsSize - 1; fast++)
        {
            swap(nums + slow, nums + fast);
            slow++;

            dfs(nums, numsSize, returnSize, returnColumnSizes, ppRes);

            slow--; // 回溯
            swap(nums + slow, nums + fast);
        }
    }

}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** ppRes = (int**)malloc(MAX_SIZE * sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(MAX_SIZE * sizeof(int));

    dfs(nums, numsSize, returnSize, returnColumnSizes, ppRes);

    return ppRes;
}
```