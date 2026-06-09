//其实我不太确定自己做的是不是dp法，内存消耗是100%最小，但是执行时间不太理想，不知道大佬们有没有啥优化方法？
//最后一步：如果N的值比0...N-1中的任意一个数小，就判断0..N-1中的dp[]的最大值。
//定义： dp[i] = 最长上升子序列中最后一个数字为i时，最长上升子序列的长度；
//子问题：0....i的整数数组中的最长上升子序列长度？
//转移方程： dp[i] = max(0...j)(j < i)(dp[j] | nums[j] < dp[i])
//最长的不一定是最后一个；
int MAX(int a, int b)
{
    return a > b ? a : b;
}
int lengthOfLIS(int* nums, int numsSize)
{
    if(numsSize == 0)
    return 0;
    if (numsSize == 1)
    return 1;
    int* dp = (int*)malloc(numsSize*sizeof(int));
    int i, j;
    int max = 0, len = 0; 
    dp[0] = 1;
    for (i = 1; i < numsSize; i++)
    {   
        for (j = 0; j < i; j++)
        {
            if(nums[i] > nums[j])
            len = MAX(len, dp[j]);
        }
        dp[i] = len + 1;
        max = MAX(max, dp[i]);
        len = 0;
    }
    return max;
}