int searchInsert(int* nums, int numsSize, int target){
     for(int i;i<numsSize;i++){
         if(nums[i] == target)
             return i;
         else if(nums[0]>target)
             return 0;
         else if(nums[numsSize-1]<target)
             return numsSize;
         else if(target<nums[i+1]&&target>nums[i])
             return i+1;
     }
    return NULL;
}