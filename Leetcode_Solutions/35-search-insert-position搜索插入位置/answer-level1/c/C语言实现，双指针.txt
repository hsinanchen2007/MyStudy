为提高效率，双指针，往中间二分法移动直到两个指针靠上或者只差1
int searchInsert(int* nums, int numsSize, int target){
    if(target < nums[0])
    {
        return 0;
    }
    
    if(target > nums[numsSize-1])
    {
        return numsSize;
    }
    
    int i = 0;
    int j = numsSize-1;
    
    while((j-i)>=1)
    {
        if(target>=nums[(i+j)/2])
        {
            i = (i+j)/2;
        }
        else
        {
            j=(i+j)/2;
        }
        if(nums[i] == target)
        {
            return i;
        }
        if(nums[j] == target)
        {
            return j;
        }
		if(j-i==1)
		{
			return j;
		}          
    }
    return j;
}
