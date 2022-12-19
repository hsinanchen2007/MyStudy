int removeDuplicates(int* nums, int numsSize){

    int length = 0;
    
    for (int i=1; i<numsSize; i++)
    {
        if(nums[length] != nums[i])
        {
            nums[++length] = nums[i];
        }
    }

    return numsSize?length+1:0;
}