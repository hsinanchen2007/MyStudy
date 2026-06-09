基本思路：mark[]记录度，start[]和end[]分别记录对应的起点和终点
```
int findShortestSubArray(int* nums, int numsSize){
    int mark[50000]={0},start[50000]={0},end[500000]={0};
    int i;
    int count=0,min;
    for(i=0;i<numsSize;i++)
    {
        mark[nums[i]]++;//记录度
        if(mark[nums[i]]>count)
        count=mark[nums[i]];//记下最大的度
        if(mark[nums[i]]==1)//第一次出现，需要设置起点
        {
            start[nums[i]]=i;
            end[nums[i]]=i;
        }
        else if(mark[nums[i]]>1)//非第一次出现
        end[nums[i]]=i;
    }
    min=50000;//寻找最大
    for(i=0;i<50000;i++)
    {
        if(mark[i]==count)//判断符合要求的
            if(end[i]-start[i]<min)
                min=end[i]-start[i];
    }
        min++;
    return min;
}

```
