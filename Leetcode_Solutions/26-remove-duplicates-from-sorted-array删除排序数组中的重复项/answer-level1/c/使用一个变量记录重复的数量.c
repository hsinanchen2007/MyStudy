int removeDuplicates(int* nums, int numsSize){
    int number = 0;
    for(int i = 0;i<numsSize-1;i++){
        if(nums[i] == nums[i+1]){
            number++;
        }else
        {
          nums[i+1-number]  = nums[i+1];
        }
    }
    return numsSize- number;

}