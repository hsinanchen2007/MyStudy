### 解题思路
两层for循环，第一个循环遍历数组中所有元素，第二层，对每个数添加子集

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int cnt =  pow(2, numsSize);// 一共有这么多结果
    int **res = (int **)malloc(cnt * sizeof(int *));
    *returnColumnSizes = (int *)malloc(cnt * sizeof(int));

    res[0] = NULL;
    *returnSize = 1;
    (*returnColumnSizes)[0] = 0;
    int idx = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < (*returnSize); j++) {
            (*returnColumnSizes)[idx] = (*returnColumnSizes)[j] + 1;
            res[idx] = (int *)malloc(sizeof(int) * (*returnColumnSizes)[idx]);
            if (res[j] != NULL) {
                for (int k = 0; k < (*returnColumnSizes)[j]; k++) {
                    res[idx][k] = res[j][k];
                }
            }
            res[idx][(*returnColumnSizes)[j]] = nums[i];
            idx++;
        }
        *returnSize = idx;
    }
    return res;
}
```