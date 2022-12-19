### 解题思路
注意点：
1. 第一层循环终止条件，index < numsSize -3;第二层循环终止条件index < numsSize -2;
2. 第二层循环的判重条件为index > k + 1;

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int **ret = NULL;
    int retSize = 0;
    int *retCol = NULL;
    if (nums == NULL || numsSize < 4) {
        *returnSize = retSize;
        *returnColumnSizes = retCol;
        return ret;
    }
    ret = (int**)malloc(sizeof(int*) * numsSize * numsSize);
    retCol = (int*)malloc(sizeof(int) * numsSize * numsSize);
    qsort(nums, numsSize, sizeof(nums[0]), cmp);

    for (int k = 0; k < numsSize - 3; k++) {

        if (k > 0 && nums[k] == nums[k - 1]) {
            continue;
        }
        int target3 = target - nums[k];

        for (int i = k + 1; i < numsSize - 2; i++) {

            if (i > k + 1 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target2 = target3 - nums[i];

            int left = i + 1, right = numsSize - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target2) {
                    int* buf = (int*)malloc(sizeof(int) * 4);
                    buf[0] = nums[k];
                    buf[1] = nums[i];
                    buf[2] = nums[left];
                    buf[3] = nums[right];
                    ret[retSize] = buf;
                    retCol[retSize++] = 4;
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }
                    ++left;
                    --right;
                } else if (nums[left] + nums[right] > target2) {
                    --right;
                } else {
                    ++left;
                }
            }
        }
    }


    *returnSize = retSize;
    *returnColumnSizes = retCol;
    return ret;
}
```