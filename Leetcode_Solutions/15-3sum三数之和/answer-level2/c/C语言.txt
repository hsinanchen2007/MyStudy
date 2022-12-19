```


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void * num1, const void * num2) {
    return (*(int *)num1 - *(int *)num2);
}

/*[-4, -1, -1, 0, 1, 2]*/
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **ret = NULL;
    int *rcs = NULL;
    int i, left, right;
    
    if (!nums || numsSize < 3) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    qsort(nums, numsSize, sizeof(int), compare);
    ret = (int **)malloc(sizeof(int *) * numsSize * numsSize);
    rcs = (int *)malloc(sizeof(int) * numsSize * numsSize);
    memset(ret, 0, sizeof(int *) * numsSize * numsSize);
    memset(rcs, 0, sizeof(int) * numsSize * numsSize);
    *returnSize = 0;
    
    for (i = 0; i < numsSize; i++) {
        left = i + 1;
        right = numsSize - 1;
        while (left < right) {
            if (nums[i] + nums[left] + nums[right] > 0) {
                /*too large, right--*/
                right--;
            } else if (nums[i] + nums[left] + nums[right] < 0) {
                /*too small, left++*/
                left++;
            } else {
                /*find one*/
                ret[*returnSize] = (int *)malloc(sizeof(int) * 3);
                ret[*returnSize][0] = nums[i];
                ret[*returnSize][1] = nums[left];
                ret[*returnSize][2] = nums[right];
                rcs[*returnSize] = 3;
                (*returnSize)++;
                /*skip the left == left + 1 and right == right + 1*/
                while ((left < numsSize - 1) && (nums[left] == nums[left + 1])) {
                    left++;
                }
                while ((right - 1 > 0) && (nums[right] == nums[right - 1])) {
                    right--;
                }
                left++;
                right--;
            }
        }

        while ((i < numsSize - 1) && (nums[i] == nums[i + 1])) {
            i++;
        }
    }
    
    *returnColumnSizes = rcs;
    return ret;
}

```
