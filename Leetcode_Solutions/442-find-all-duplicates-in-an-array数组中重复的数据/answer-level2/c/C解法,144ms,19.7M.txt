数组值作为索引。
```

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int cnt = 0;
    int *tmp = (int *)malloc(numsSize * sizeof(int));

    memset(tmp, 0, numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        tmp[nums[i] - 1]++;
        if (tmp[nums[i] - 1] == 2) {
            cnt++;
        }
    }
    int *output = (int *)malloc(cnt * sizeof(int));
    cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (tmp[i] == 2) {
            output[cnt] = i + 1;
            cnt++;
        }
    }
    *returnSize = cnt;
    free(tmp);
    return output;
}
```
