```
#define MAX_SIZE 10000
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **result = (int**)malloc(MAX_SIZE * sizeof(int*));
    memset(result, 0, MAX_SIZE * sizeof(int*));
    *returnColumnSizes = (int*)malloc(MAX_SIZE * sizeof(int));
    memset(returnColumnSizes[0], 0, MAX_SIZE * sizeof(int));
    if (numsSize == 0) {
        *returnSize = 1;
        returnColumnSizes[0][0] = 0;
        return result;
    }
    int len = 1 << numsSize;
    for (int i = 1; i < len; i++) {
        result[i] = (int*)malloc(MAX_SIZE * sizeof(int));
        memset(result[i], 0, MAX_SIZE * sizeof(int));
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if ((1 << j) & i) {
                result[i][count++] = nums[j];
            }
        }
        returnColumnSizes[0][i] = count;
    }
    *returnSize = len;
    return result;
}
```
