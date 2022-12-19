```
int cmp(const int *a, const int *b)
{
    return (*(int *)a - *(int *)b);
}

int singleNumber(int* nums, int numsSize){
#if 1  
    qsort(nums, numsSize, sizeof(int), cmp);

    int sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
             sum -=  nums[i - 1];
        } else {
            sum += nums[i];
        }
    }
    
    return sum;
#else 
    int ret = 0;
    for (int i = 0; i < numsSize; i++) {
        ret ^= nums[i];
    }
    return ret;

#endif
}
```
