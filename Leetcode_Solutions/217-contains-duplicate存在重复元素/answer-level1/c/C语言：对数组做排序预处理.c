```
int cmp(const void* a,const void* b) {
    return *(int*)a - *(int*)b;
}

bool containsDuplicate(int* nums, int numsSize){
    if(numsSize < 2) {
        return false;
    }
    qsort(nums,numsSize,sizeof(int),cmp);
    for(int i = 0;i < numsSize - 1;i++) {
        if(nums[i] == nums[i+1]) {
            return true;
        }
    }
    return false;
}
```
