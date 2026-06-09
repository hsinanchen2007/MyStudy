```
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int singleNumber(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int i;
    for(i = 0; i < numsSize-1; i++){
        if(nums[i]==nums[i+1]) ++i;
        else return nums[i];
    }
    return nums[numsSize-1];
}
```
