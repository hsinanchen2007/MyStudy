方法一：基本的动态规划
```
int lengthOfLIS(int* nums, int numsSize){
    if(numsSize==0)
    return 0;
    int max=1,i,j;
    int dp[numsSize];
    for(i=0;i<numsSize;i++)
    dp[i]=1;
    for(i=1;i<numsSize;i++)
    {
        for(j=0;j<i;j++)
        {
            if(nums[i]>nums[j]&&dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                if(dp[i]>max)
                max=dp[i];
            }
        }
    }
    return max;
}
```
方法二：栈
```
int lengthOfLIS(int* nums, int numsSize){
    if(numsSize==0)
    return 0;
    int stack[numsSize],i=0,top=0,j;
    stack[top++]=nums[0];
    for(i=1;i<numsSize;i++)
        {
            if(nums[i]>stack[top-1])//大于栈顶元素，入栈
            stack[top++]=nums[i];
            else
            {//小于栈顶元素
                for(j=0;j<top;j++)
                if(nums[i]<=stack[j])
                {
                    stack[j]=nums[i];
                    break;
                }
            }
        }
    return top;
}
```
方法三：栈+二分查找
```
int lengthOfLIS(int* nums, int numsSize){
    if(numsSize==0)
    return 0;
    int stack[numsSize],i=0,top=0,j;
    int low,high,mid;
    stack[top++]=nums[0];
    for(i=1;i<numsSize;i++)
        {
            if(nums[i]>stack[top-1])//大于栈顶元素，入栈
            stack[top++]=nums[i];
            else
            {//小于栈顶元素
                low=0;
                high=top-1;
                while(high>=low)
                {
                    mid=(low+high)/2;
                    if(stack[mid]>=nums[i])
                    high=mid-1;
                    else
                    low=mid+1;
                }
                stack[high+1]=nums[i];
            }
        }
    return top;
}
```


