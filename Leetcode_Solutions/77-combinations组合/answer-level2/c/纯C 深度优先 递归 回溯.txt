### 解题思路
纯C 深度优先 递归 回溯

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 50000

static void dfs(int n, int k, int* returnSize, int** returnColumnSizes,
                int** ppRes, int* pBuffer, bool* pbUsed)
{
    static int length = 0;
    static int slow = 1;
    int fast = 0;

    if (length == k)
    {
        ppRes[*returnSize] = (int*)malloc(k * sizeof(int));
        memcpy(ppRes[*returnSize], pBuffer, k * sizeof(int));
        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
    }
    else
    {
        for (fast = slow; fast <= n; fast++)
        {   
            if (false == pbUsed[fast])
            {
                pBuffer[length] = fast;
                pbUsed[fast] = true;
                slow = fast + 1;
                length++;

                dfs(n, k, returnSize, returnColumnSizes, ppRes, pBuffer, pbUsed);

                length--; // 回溯
                pbUsed[fast] = false;
            }
        }
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int** ppRes = (int**)malloc(MAX_SIZE * sizeof(int*));
    int* pBuffer = (int*)malloc(k * sizeof(int));
    bool* pbUsed = (bool*)malloc((n + 1) * sizeof(bool)); // 第一个没用，因为从1开始
    memset(pbUsed, false, (n + 1) * sizeof(bool));

    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(MAX_SIZE * sizeof(int));

    dfs(n, k, returnSize, returnColumnSizes, ppRes, pBuffer, pbUsed);

    return ppRes;
}
```