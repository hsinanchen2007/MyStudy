int jump(int* nums, int numsSize){
    int i=0,j,tmp,index=0;
    if(numsSize==1){
        return 0;
    }
    while(1){
        tmp=i;
        if(nums[i]+i>=numsSize-1){
            return index+1;
        }
        for(j=tmp;j<=tmp+nums[tmp] && j<numsSize;j++){
            if(nums[j]+j>=nums[i]+i){
                i=j;
            }
        }
        index++;
    }
}