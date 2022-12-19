暴力法
```c#
public class Solution
{
    public int MaxSubArray(int[] nums)
    {
        int max = nums[0];
        int sum = nums[0];
        
        for(int i = 1; i < nums.Length; ++i)
        {
            if(sum < 0) //前面的部分贡献为负数，故舍去
            {
                sum = 0;
            }
            sum = sum + nums[i];
            max = Math.Max(sum, max);
        }
        
        return max;
    }
}
```

DP
```c#
public class Solution
{
    public int MaxSubArray(int[] nums)
    {
        int[] dp = new int[nums.Length + 1];
        dp[0] = nums[0];

        int max = nums[0];
        for (int i = 1; i < nums.Length; ++i)
        {
            dp[i] = Math.Max(dp[i - 1] + nums[i], nums[i]);
            max = Math.Max(dp[i], max);
        }
        return max;
    }
}
```