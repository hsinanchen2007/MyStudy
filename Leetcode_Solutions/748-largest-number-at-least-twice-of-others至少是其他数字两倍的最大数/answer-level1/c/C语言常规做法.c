先遍历一次找到最大元素值和下标，再遍历一次找到第二大元素值，初始化时令max等于nums[0]，令max_2nd等于0，以处理特殊情况。
注意，一次遍历找到最大元素值和第二大元素值易出错，所以遍历两次较为保险，时间复杂度均为O(N)。
```c
int dominantIndex(int* nums, int numsSize){
    short max=nums[0],max_index=0,max_2nd=0,i;
    for(i=0;i<numsSize;i++)
        if(nums[i]>max){
            max=nums[i];
            max_index=i;
        }
    for(i=0;i<numsSize;i++)
        if(nums[i]<max&&nums[i]>max_2nd) max_2nd=nums[i];
    if(max>=max_2nd*2) return max_index;
    else return -1;
}
```