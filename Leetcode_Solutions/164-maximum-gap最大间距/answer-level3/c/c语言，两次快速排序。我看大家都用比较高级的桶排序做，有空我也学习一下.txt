int compare(const void *p1, const void *p2) {
    return *(int *)p1 - *(int *)p2;
}

int maximumGap(int* nums, int numsSize){
    if (numsSize < 2) {
        return 0;
    }

    int tmpArray[numsSize - 1];
    int i;

    qsort(nums, numsSize, sizeof(int), compare);

    for (i = 0; i < numsSize - 1; i++) {
        tmpArray[i] = nums[i + 1] - nums[i];
    }
    
    qsort(tmpArray, numsSize - 1, sizeof(int), compare);
    return tmpArray[numsSize - 2];
}