int missingNumber(int* nums, int numsSize){
    int k=numsSize;
    int m=k*(k+1)/2;
    int count=0;
    for(int i=0;i<k;i++)
    {
        count=count+nums[i];
    }
    return m-count;
}