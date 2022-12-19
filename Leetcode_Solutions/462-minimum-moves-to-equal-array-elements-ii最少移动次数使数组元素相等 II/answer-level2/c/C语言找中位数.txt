用qsort排序然后中间那个就是，剩下的就是所有数和中位数的差和。
int cmp(const void* a,const void* b){
    return ((*(int *)a - *(int *)b));
}
    
int minMoves2(int* nums, int numsSize){
    int mid,count;
    if(numsSize==1){
        return 0;
    }
    if(numsSize==2){
        return abs(nums[1]-nums[0]);
    }
    qsort(nums,numsSize,sizeof(int),cmp);
    mid=nums[numsSize/2];
    count=0;
    for(int i=0;i<numsSize;i++){
        count+=abs(mid-nums[i]);
    }
    return count;
}
