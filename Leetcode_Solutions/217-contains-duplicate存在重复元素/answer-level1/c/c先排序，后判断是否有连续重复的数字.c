```
int comp(const void *a,const void *b){
    return (*(int*)a > *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), comp);
    int count = 1;
    for (int i=1; i<numsSize; i++) {
        if (nums[i]>nums[i-1]) {
            if (count >= 2) {
                return true;
            }
            count = 1;
        } else {
            count++;
        }
    }
    if (count >= 2) {
        return true;
    }
    return false;
}

```
