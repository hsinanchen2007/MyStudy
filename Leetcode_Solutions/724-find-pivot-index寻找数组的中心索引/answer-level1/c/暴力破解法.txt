

int pivotIndex(int* nums, int numsSize){
    if(nums == NULL || numsSize==0) {
        return -1;
    }
    int lSum=0;
    int rSum=0;
    for(int i=1; i<numsSize; i++) {
        rSum += nums[i];
    }
    for(int j=0; j<numsSize; j++) {
        if(lSum==rSum) {
            return j;
        }
        
        if(j < numsSize - 1) {
            lSum += nums[j];
            rSum -= nums[j+1];    
        }
    }
    return -1;
}
