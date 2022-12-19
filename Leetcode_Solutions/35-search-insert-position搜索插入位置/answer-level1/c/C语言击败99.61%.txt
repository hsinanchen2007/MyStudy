int searchInsert(int* nums, int numsSize, int target){
    
    if(numsSize == 0)return 0; //当nmusSize为0时，直接就返回0
    for(int i = 0;i<numsSize;i++)
    {
        if(nums[i]>=target)
        {
            return i;
        }
    }
    
    return numsSize;
}