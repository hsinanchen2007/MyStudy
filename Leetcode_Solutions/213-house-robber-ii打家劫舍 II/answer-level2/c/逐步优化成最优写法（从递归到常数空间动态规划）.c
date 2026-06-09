解题优化：递归->记忆化搜索->一维数组dp->常数级dp
动态转移方程：dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
# 递归
```c
int robs(int *nums,int begin,int i)
{
    if(i<begin)
        return 0;
    return fmax(robs(nums,begin,i-2)+nums[i],robs(nums,begin,i-1));
}

int rob(int* nums, int numsSize){
    if(numsSize==1)return nums[0];
    return fmax(robs(nums,0,numsSize-2),robs(nums,1,numsSize-1));
}
```
递归方法肯定超时

# 记忆化搜索
```c
int robs(int *nums,int begin,int i,int *memo)
{
    if(i<begin)
        return 0;
    else if(memo[i]>-1)
        return memo[i];
    memo[i]=fmax(robs(nums,begin,i-2,memo)+nums[i],robs(nums,begin,i-1,memo));
    return memo[i];
}

int rob(int* nums, int numsSize){
    if(numsSize==1)return nums[0];
    int *memo1=(int *)malloc(sizeof(int)*numsSize);
    int *memo2=(int *)malloc(sizeof(int)*numsSize);
    memset(memo1,-1,sizeof(int)*numsSize);
    memset(memo2,-1,sizeof(int)*numsSize);
    return fmax(robs(nums,0,numsSize-2,memo1),robs(nums,1,numsSize-1,memo2));
}
```

# 动态规划一维空间
```c
int rob(int* nums, int numsSize){
    if(numsSize==1)return nums[0];
    int *dp1=(int *)malloc(sizeof(int)*(numsSize+1));
    int *dp2=(int *)malloc(sizeof(int)*(numsSize+1));
    memset(dp1,0,sizeof(int)*(numsSize+1));
    memset(dp2,0,sizeof(int)*(numsSize+1));
    for(int i=2;i<numsSize+1;i++)
    {
        dp1[i]=fmax(dp1[i-1],dp1[i-2]+nums[i-2]);
        dp2[i]=fmax(dp2[i-1],dp2[i-2]+nums[i-1]);
    }
    return fmax(dp1[numsSize],dp2[numsSize]);
}
```
# 动态规划常数级空间
```c
int rob(int* nums, int numsSize){
    if(numsSize==1)return nums[0];
    int cur_max1=0,cur_max2=0;//dp[-1]=0;
    int pre_max1=0,pre_max2=0;//dp[-2]=0;
    for(int i=0;i<numsSize-1;i++)
    {
        int temp=cur_max1;//保存dp[i-1];
        cur_max1=fmax(pre_max1+nums[i],cur_max1);//fmax(dp[i-2]+nums[i],dp[i-1]);
        pre_max1=temp;
        temp=cur_max2;
        cur_max2=fmax(pre_max2+nums[i+1],cur_max2);
        pre_max2=temp;
    }
    return fmax(cur_max1,cur_max2);
}
```
