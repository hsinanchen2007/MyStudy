```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int *hash = (int *)malloc(sizeof(int) * (numsSize + 1));
    memset(hash, 0, sizeof(int) * (numsSize + 1));

    if (numsSize == 0) {
        *returnSize = 0;
        return hash;
    }

    if (numsSize == 1) {
        *returnSize = 0;
        return hash;
    }

    for (int i = 0; i < numsSize; i ++) {
        hash[nums[i]]++;
    }
    
    int cnt = 0;
    for (int i = 1; i < numsSize + 1; i++) {
        if (hash[i] == 0) {
            hash[cnt++] = i;
        }
    }

    *returnSize = cnt;
    return hash;
}
```
