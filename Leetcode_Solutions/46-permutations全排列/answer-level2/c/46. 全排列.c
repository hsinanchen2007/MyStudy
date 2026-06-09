### 解题思路
比较难看到C写得答案，参考大神们的思路，写了一个；

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// 为啥要900，试的，刚开始给了10000
#define RETSIZE 900 
void Dfs(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int** ret, int* retEach, int* visitedFlag, int depth);
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if (nums == NULL) {
        return NULL;
    }
    *returnSize = 0;
    // 分配返回数组资源
    int **ret = (int**)malloc(sizeof(int*) * RETSIZE);
    if (ret == NULL) {
        return NULL;
    }    
    memset(ret, 0, sizeof(int*) * RETSIZE);
    // 分配返回数组每列长度资源
    *returnColumnSizes =  (int*)malloc(sizeof(int) * RETSIZE);
    memset(*returnColumnSizes, 0, sizeof(int) * RETSIZE);
    // 存储一次排列中已遍历的数据
    int *retEach = (int*)malloc(sizeof(int) * numsSize);
    if (retEach == NULL) {
        return NULL;
    }
    memset(retEach, 0, sizeof(int) * numsSize);
    // 存储已遍历标志
    int *visitedFlag = (int*)calloc(sizeof(int), numsSize);    
    Dfs(nums, numsSize, returnSize, returnColumnSizes, ret, retEach, visitedFlag, 0);
    // 释放临时资源
    free(visitedFlag);
    free(retEach);
    return ret;
}

void Dfs(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int** ret, int* retEach, int* visitedFlag, int depth)
{

    if (depth == numsSize) {
        int *eachRet = (int*)malloc(sizeof(int) * numsSize);
        if (eachRet == NULL) {
            return;
        }
        memcpy(eachRet, retEach, sizeof(int) * numsSize);
        ret[*returnSize] = eachRet;    
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (!visitedFlag[i]) {
            retEach[depth] = nums[i];
            visitedFlag[i] = 1;
            Dfs(nums, numsSize, returnSize, returnColumnSizes, ret, retEach, visitedFlag, depth + 1);
            visitedFlag[i] = 0;
        }
    }
}
```