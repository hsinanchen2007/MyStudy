```
#define RETSIZE 1000 
void backtrace(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int** ret, int* retEach, int* visitedFlag, int depth);

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
    backtrace(nums, numsSize, returnSize, returnColumnSizes, ret, retEach, visitedFlag, 0);
    // 释放临时资源
    free(visitedFlag);
    free(retEach);
    return ret;
}

void backtrace(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int** ret, int* retEach, int* visitedFlag, int depth)
{
    //满足条件结束递归
    if (depth == numsSize) {
        ret[(*returnSize)] = (int*)malloc(sizeof(int*)*depth); 
        for(int i = 0; i < numsSize; i++ ) {
            ret[*returnSize][i] = retEach[i];
        }
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (visitedFlag[i]) continue;
        retEach[depth] = nums[i];
        //选择
        visitedFlag[i] = 1;
        //进行回溯
        backtrace(nums, numsSize, returnSize, returnColumnSizes, ret, retEach, visitedFlag, depth + 1);
        //撤销选择
        visitedFlag[i] = 0;
    }
}
```
