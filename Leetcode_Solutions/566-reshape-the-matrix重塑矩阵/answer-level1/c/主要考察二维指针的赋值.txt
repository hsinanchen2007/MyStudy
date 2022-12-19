### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define LEN 10002
int** matrixReshape(int** nums, int numsSize, int* numsColSize, int r, int c, int* returnSize, int** returnColumnSizes)
{
    int arr[LEN] = {0};
    int arr_id = 0;
    int **ans;
    
    ans = (int **)malloc(sizeof(int *) * r);
    for (int i = 0; i < r; i++) {
        ans[i] = (int *)malloc(sizeof(int) * c);
        //注意这里空间的开辟
        *returnColumnSizes = (int *)malloc(sizeof(int) * r);
    }
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsColSize[i]; j++) {
            arr[arr_id++] = nums[i][j];
        }
    }
    if (r * c != numsSize * (*numsColSize)) {
        *returnSize = numsSize;
        *returnColumnSizes = numsColSize;
        return nums;
    }
    int tmp_id = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
           ans[i][j] = arr[tmp_id++];
        }
        (*returnColumnSizes)[i] = c;
    }
    *returnSize = r;
    return ans;
}
```