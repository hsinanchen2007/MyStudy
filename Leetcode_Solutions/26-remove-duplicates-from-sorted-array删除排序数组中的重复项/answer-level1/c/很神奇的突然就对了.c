```
int removeDuplicates(int* nums, int numsSize){
    int i, j = 0;
    if(numsSize == 0) return 0;
    if(numsSize == 1) return 1;

    for(i = 0; i < numsSize-1; i++){
        if(nums[i]==nums[i+1]){
            if(j!=0 && nums[i]==nums[j-1])
                continue;
        }
        else nums[j++] = nums[i];
    }
    nums[j] = nums[numsSize-1];
    return j+1;
}
```
