bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    int i,j,t;
    for(i=0;i<numsSize;i++)
    {
        t=(i-k)>0?(i-k):0;
        for(j=t;j<i;j++){
            if(nums[i] == nums[j])
                return true;
        }
    }
    return false;

}