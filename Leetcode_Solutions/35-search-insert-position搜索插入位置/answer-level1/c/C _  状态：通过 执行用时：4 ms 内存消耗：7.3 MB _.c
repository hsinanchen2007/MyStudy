int searchInsert(int* nums, int numsSize, int target){
    int i;
    if(nums==NULL){return 0;}
    for(i=0;i<numsSize;i++){
        if(nums[i]>=target){
            return i;
        }
        if(i==numsSize-1){return i+1;}
    }
    return 0;
}