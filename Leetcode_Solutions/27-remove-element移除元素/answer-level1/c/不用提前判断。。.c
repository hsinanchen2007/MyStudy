int removeElement(int* nums, int numsSize, int val){
    int i,repeat = 0;
    int notrepeat = 0;
    for (i=0;i<numsSize;i++) {
        if (nums[i]==val) {
            repeat++;
        }
        if (nums[i]!=val) {
            nums[notrepeat] = nums[i];
            notrepeat++;
        }
    }
    return numsSize-repeat;
}