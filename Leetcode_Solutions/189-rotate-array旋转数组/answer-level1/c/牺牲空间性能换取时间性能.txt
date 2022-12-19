void rotate(int* nums, int numsSize, int k)
{
    if(nums == NULL || numsSize <=0 || k<=0)return;
    if(k>numsSize)k=k%numsSize;
    int temp[numsSize];
    memcpy(temp,nums,sizeof(int)*numsSize);
    //printf("%d\n",temp[numsSize-1]);
    memcpy(nums+k,temp,sizeof(int)*(numsSize-k));
    memcpy(nums,temp+numsSize-k,sizeof(int)*k);
    return ;

}