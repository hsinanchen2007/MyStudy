int removeElement(int* nums, int numsSize, int val){
    
    int left = 0;
    int right = numsSize - 1;
    
    while(left <= right)
    {
        if(nums[left] == val)
        {
            nums[left] = nums[right];
            right--;
            numsSize--;
        }
        else
        {
            left++;
        }
    }
    
    if(left == 0 && right == 0)
        return NULL;
    
    return numsSize;   

}