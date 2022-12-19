最朴素的方法，两次遍历，希望自己相处更优化的算法。



int searchInsert(int* nums, int numsSize, int target){
    int i;
    for(i = 0;i<numsSize;i++){
        if(target == nums[i]) {
            return i;
        }
    }
    for(i = 0;i<numsSize;i++){
        if(target <= nums[i]) {
            return i;
        }
    }
    return numsSize;
}
