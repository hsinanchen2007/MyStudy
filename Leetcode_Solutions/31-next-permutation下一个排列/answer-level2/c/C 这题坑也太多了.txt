```
void nextPermutation(int* nums, int numsSize){
    if(numsSize<=1)return;//只有一个元素直接返回
    int p1;
    int i,j;
    for(i=numsSize-2;i>=0;i--)
    {
        if(nums[i]<nums[i+1])
        {
            p1=i;
            break;
        }
    }
    if(i<0)//目前已经是最后一个，把原数组翻转后返回
    {
        for(i=0,j=numsSize-1;i<j;i++,j--)
        {
            int t=nums[i];
            nums[i]=nums[j];
            nums[j]=t;
        }
        return;
    }

    //一般情况的做法
    int p2,bigger=INT_MAX;
    for(int i=p1+1;i<numsSize;i++)
    {
        if(nums[i]>nums[p1])
        {
            if(nums[i]<=bigger)
            {
                bigger=nums[i];
                p2=i;
            }
        }
    }

    int t=nums[p1];
    nums[p1]=nums[p2];
    nums[p2]=t;

    //reverse(nums,p1+1,numsSize);
    for(i=p1+1,j=numsSize-1;i<j;i++,j--)
    {
        int t=nums[i];
        nums[i]=nums[j];
        nums[j]=t;
    }
}
```
