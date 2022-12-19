```
int findShortestSubArray(int* nums, int numsSize){
int sum[50000]={0},first[50000],last[50000]={0};
    int i,min=50000,max=0;
    memset(first,-1,50000);
    for(i=0;i<numsSize;i++)
    {
        sum[nums[i]]++;
        if(first[nums[i]]==-1)
            first[nums[i]]=i;
            last[nums[i]]=i;
         if(max<sum[nums[i]])
             max=sum[nums[i]];
    }
    for(i=0;i<numsSize;i++)
    {
        if(sum[nums[i]]==max)
        {
            if(min>last[nums[i]]-first[nums[i]]+1)
                min=last[nums[i]]-first[nums[i]]+1;
            if(min==max)
                return min;
        }
    }
    return min;
}

```