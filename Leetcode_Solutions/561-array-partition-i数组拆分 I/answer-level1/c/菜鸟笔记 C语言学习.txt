官方题解2的实现。
在配对过程中，较大的那个数将不会参与计算，因此应尽量使每对数中较大的那个数越小越好。
```
int comp(const void* a, const void* b){
    return (*(int*)a > *(int*)b);
}

int arrayPairSum(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), comp);
    int sum = 0;
    for(int i=0;i<numsSize;i+=2){
        sum += nums[i];
    }
    return sum;
}
```
