```
int comp(const void* p, const void* q)
{
    return (*( int*)p - *(int*)q) ;
}

bool containsDuplicate(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), comp);
    int i, j;
    for(i = numsSize - 1; i > 0; i--) {
        if(nums[i] == nums[i - 1]) {
            return true;    
        } 
    }
    return false;
}
```
