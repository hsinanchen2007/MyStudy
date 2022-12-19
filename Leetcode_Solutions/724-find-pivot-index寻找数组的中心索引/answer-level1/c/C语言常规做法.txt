先求出数组元素之和，后续遍历时只需要加减单个元素即可比较两边大小。时间复杂度为O(N)。
```c
int pivotIndex(int* nums, int numsSize){
    if(numsSize<3) return -1;
    int i,left_sum=0,right_sum=0;
    for(i=1;i<numsSize;i++) right_sum=right_sum+nums[i];
    if(right_sum==0) return 0;
    for(i=1;i<numsSize;i++){
        left_sum=left_sum+nums[i-1];
        right_sum=right_sum-nums[i];
        if(left_sum==right_sum) return i;
    }
    return -1;
}
```