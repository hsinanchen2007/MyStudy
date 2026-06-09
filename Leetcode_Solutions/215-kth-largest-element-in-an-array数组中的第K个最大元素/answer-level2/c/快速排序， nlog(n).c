

```
int cmp(const void* _a , const void* _b)
{
    int* a = (int*)_a;
    int* b = (int*)_b;
    return -(*a - *b);
}

int findKthLargest(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[k-1];
}
```
