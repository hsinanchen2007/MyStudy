```
int searchInsert(int* nums, int numsSize, int target){
    if(target <= 0) return 0;
    /*
        加上多4ms？？？
        if(nums[numsSize-1] == target) return numsSize-1;
        if(nums[numsSize-1] < target) return numsSize;
    */
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>=target)
        {
            return i;
        }
    }
    return numsSize;
}
```
