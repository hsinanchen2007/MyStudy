方法一：基本思想：一次遍历，判断是否和后续元素发生逆序。只不过需要注意一下是顺序的特殊情况以及长度为0和1的时候的情况即可。
```
int findLengthOfLCIS(int* nums, int numsSize){
    int max=0,count=1,i;//对于序列的长度，至少会达到1
    if(numsSize==0)//考虑到极端情况
    return 0;
    for(i=0;i<numsSize-1;i++)
    {
        if(nums[i]<nums[i+1])//经过试验，相同的元素不算入递增
                count++;
        else//逆序的情况
        {
            if(count>max)
            {
                max=count;
            }
            count=1;
        }
    }
    if(count>max)//防止全部顺序，不出现逆序的情况
        max=count;
    return max;
}
```
方法二：动态规划

没有啥难度，不懂的欢迎留言
```
int findLengthOfLCIS(int* nums, int numsSize){  
    if(numsSize==0)
    return 0;
    int dp[numsSize];//1以nums[i]结尾的递增子序列的长度
    int i,max=1;
    for(i=0;i<numsSize;i++)//初始化
    dp[i]=1;
    for(i=1;i<numsSize;i++)
    if(nums[i]>nums[i-1])
        {
            dp[i]=dp[i-1]+1;
            if(dp[i]>max)
            max=dp[i];
        }
    return max;
}
```

