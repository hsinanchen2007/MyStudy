int removeElement(int* nums, int numsSize, int val){
    int indexflag = -1;
    int deleted = 0;
    //foreach array data from first
    for(int i=0;i<numsSize;i++){
        if(nums[i]==val){
            indexflag = i;
            deleted=1;
            break;
        }else{
            continue;
        }
    }
    if(deleted==1){
        for(int i = indexflag;i<numsSize-1;i++){
            nums[i]=nums[i+1];
        }
        numsSize -=1;
        numsSize = removeElement(nums,numsSize,val);
    }
    
    return numsSize;
}