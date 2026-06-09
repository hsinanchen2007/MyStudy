```
long long int cmp(const void *a, const void *b) {
    return (long long int)(*(int *)a) - (long long int)(*(int *)b);
}

int longestConsecutive(int* nums, int numsSize){
    if ((nums == NULL) || (numsSize == 0)) {
        return 0;
    }
    if (numsSize == 1) {
        return 1;
    }

    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    //printf("nums[0]: %d\n", nums[0]);
    int i;
    int j;
    int size = 0;
    long long int tmpValue = 0;
    int tmpSize = 0;
    for (i = 0; i < numsSize - 1; i++) {
        tmpValue = nums[i];
        tmpSize = 0;
        for (j = i + 1; j < numsSize; j++) {
            if((nums[j] - tmpValue) == 1) {
                tmpValue = nums[j];
                tmpSize++;
            }
        }
        tmpSize = tmpSize + 1;
        if (size < tmpSize) {
            size = tmpSize;
        }
    }

    return size;
}
```
