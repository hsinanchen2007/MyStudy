int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0){
        return 0;
    }
    int cnt = 0;
    for(int i = 0;i<numsSize-1;i++){
        if(nums[i]!=nums[i+1]){
            nums[cnt++] = nums[i];
        }
    }
    nums[cnt++] = nums[numsSize-1];
    return cnt;
}