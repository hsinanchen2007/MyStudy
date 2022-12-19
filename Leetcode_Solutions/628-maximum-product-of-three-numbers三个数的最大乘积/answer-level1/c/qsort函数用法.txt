int maximumProduct(int* nums, int numsSize){
    int cmp(const void* a,const void* b) {
        return *(int*)a - *(int*)b;
    }
    int sum1 = 0;
    int sum2 = 0;
    qsort(nums,numsSize,sizeof(nums[0]),cmp);
    sum1 = nums[0] * nums[1] * nums[numsSize - 1];
    sum2 = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
    if(sum1 > sum2) 
       return sum1;
    else
       return sum2;
}