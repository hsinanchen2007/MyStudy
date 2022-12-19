```


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if ((nums == NULL) || (numsSize < k)) {
        *returnSize = 0;
        return NULL;
    }
    if (k == 1) {
        *returnSize = numsSize;
        return nums;
    }
    int *step = (int *)malloc(numsSize * sizeof(int));
    int *res = (int *)malloc((numsSize - k + 1) * sizeof(int));

    int index = 0;
    int max = nums[0];

    for (int i = 0; i < k; i++) {
        if (nums[i] >= max) {
            index = i;
            max = nums[i];
        }
    }
    step[k - 1] = max;

    for (int i = k; i < numsSize; i++) {
        if (i - index >= k) {
            max = nums[index + 1];
            index = index + 1;
            for (int j = index + 1; j <= i; j++) {
                if (nums[j] >= max) {
                    index = j;
                    max = nums[j];
                }
            }
        }
        if (nums[i] >= max) {
            max = nums[i];
            index = i;
        }
        step[i] = max;
    }
    *returnSize = numsSize - k + 1;
    for (int i = 0; i < numsSize - k + 1; i++) {
        res[i] = step[i + k -1];
    }
    free(step);
    return res;
}


```
