```c

int cmp(const void* a, const void* b){
    return *(int*)a > *(int*)b;
}
int singleNumber(int* nums, int numsSize){
    if (numsSize == 1)
        return nums[0];
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    if (nums[0] != nums[1])
        return nums[0];
    // for (int i = 0; i < numsSize; i++)
    //     printf("%d ", nums[i]);
    int i = 1;
    for (; i < numsSize - 1; i++){
        if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
            break;
    }
    return nums[i];
}


```