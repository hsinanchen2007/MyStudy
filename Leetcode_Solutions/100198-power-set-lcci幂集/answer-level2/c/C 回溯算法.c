### 解题思路
由于子集[1,2] 和 [2,1]属于同一个，所以每次递归的起点要从当前位置的下一个开始；
参数** returnColumnSizes有点变态，被折磨了好久
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SUBSET_NUM 1500
 void BackTrace(int **subsetArr, int *nums, int numsSize, int *returnSize, int *tmp, int size, int pos, 
                int** returnColumnSizes, int startIndex)
 {
     if (pos == size) {
         for (int i = 0; i < size; i++) {
            subsetArr[*returnSize][i] = tmp[i];
         }

        (*returnColumnSizes)[*returnSize] = size;
        (*returnSize)++;
        return;
     }
     for (int i = startIndex; i < numsSize; i++) {
         tmp[pos++] = nums[i];
         BackTrace(subsetArr, nums, numsSize, returnSize, tmp, size, pos, returnColumnSizes,i + 1);
         pos--;
     }
     return;
 }
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **subsetArr = (int **)malloc(sizeof(int *) * MAX_SUBSET_NUM);
    int cloumCount = 0;
    *returnSize = 0;
    if (nums == NULL) {
        *returnColumnSizes = 0;
        return NULL;
    }
    for (int j = 0; j < MAX_SUBSET_NUM; j++) {
        subsetArr[j] = (int *)malloc(sizeof(int) * numsSize);
        memset(subsetArr[j], 0, sizeof(int) * numsSize);
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * MAX_SUBSET_NUM);
    memset(*returnColumnSizes, 0, sizeof(int) * MAX_SUBSET_NUM);
    int *tmp = (int *)malloc(sizeof(int) * numsSize);
    subsetArr[(*returnSize)++] = NULL;
    (*returnColumnSizes)[cloumCount++] = 0;
    for (int i = 1; i <= numsSize; i++) {
        BackTrace(subsetArr, nums, numsSize, returnSize, tmp, i, 0, returnColumnSizes, 0);
    }
    return subsetArr;
}
```