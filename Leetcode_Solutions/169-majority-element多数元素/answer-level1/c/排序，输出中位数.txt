int cmp_int(void *_a, void *_b) {
    int *a = (int*)_a;
    int *b = (int*)_b;
    return *a - *b;
}

int majorityElement(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(nums[0]), cmp_int);

    return nums[numsSize/2];
}