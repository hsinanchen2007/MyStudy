int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}

int maximumProduct(int* nums, int numsSize){
     int sum1=0,sum2=0;
     if(numsSize==3)
         return nums[0]*nums[1]*nums[2];
     qsort(nums,numsSize,sizeof(int),cmp);
     sum1=nums[0]*nums[1]*nums[numsSize-1];
     sum2=nums[numsSize-1]*nums[numsSize-2]*nums[numsSize-3];
     return (sum1>sum2)?sum1:sum2;
}