```
#define CAP 10000
int idx = 0;
int **permuteRecur(int *nums, int numsSize, int *returnSize, int *ColumnSizes, int **result, int *arry, int currSize, int *visitd) {
        if (nums == NULL || numsSize <=0 ) {
        return 0;
    }
    if (currSize == numsSize) {
        result[*returnSize] = malloc(sizeof(int)*numsSize);
        ColumnSizes[*returnSize] = numsSize;
        memcpy(result[*returnSize], arry, sizeof(int)*numsSize);
        (*returnSize)++;
        return 0;
    }
    for (int i = 0; i < numsSize; i++) {
        if (visitd[i] == 0) {
            arry[idx++] = nums[i]; 
            visitd[i] = 1;
            permuteRecur(nums, numsSize, returnSize, ColumnSizes, result, arry, currSize+1, visitd);
            idx--;
            visitd[i] = 0;
        }
    }
 
    return result;
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **result = malloc(sizeof(int*)*CAP);
    int *arry = malloc(sizeof(int)*numsSize);
 //   int arry[3] = {0};
    *returnSize = 0;
    int currSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int)*10000);
    int *visted = calloc(numsSize, sizeof(int));
    result = permuteRecur(nums, numsSize, returnSize, *returnColumnSizes, result, arry, currSize, visted);
    return result;
}
```
