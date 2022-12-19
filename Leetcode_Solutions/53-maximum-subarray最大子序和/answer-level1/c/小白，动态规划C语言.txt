//最后一步： 这个最大和连续子数组中，一定最后一个数K，使得K + （最大和连续数组中除了K以外的数之和）
//子问题： 找一个满足 和 = （最大和 - k）的连续子数组
//初始化： dp[0] = nums[0];
//只不过dp[n-1]不一定是最大和;
//转移方程：  dp[i] = dp[i] + nums[i-1];
int maxSubArray(int* nums, int numsSize)
{
    int* dp = (int*)malloc(numsSize*sizeof(int));
    int max = nums[0]; //用来记录dp[0....numsSize-1]中的最大值;
    dp[0] = nums[0];
    int i;
    for (i = 1; i < numsSize; i++)
    {
        dp[i] = (nums[i] < (dp[i-1] + nums[i]) ? (dp[i-1] + nums[i]) : nums[i]);
        max = (dp[i] > max ? dp[i] : max);
    }
    return max;
}
