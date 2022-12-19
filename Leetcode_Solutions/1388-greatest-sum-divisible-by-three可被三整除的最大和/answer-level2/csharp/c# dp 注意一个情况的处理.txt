注意一个情况的处理
```c#
public class Solution
{
    public int MaxSumDivThree(int[] nums)
    {
        int[,] dp = new int[40005, 3];

        dp[1, nums[0] % 3] = nums[0];
        for (int i = 2; i <= nums.Length; ++i)
        {
            int c = nums[i - 1] % 3;
            for (int j = 0; j < 3; ++j)
            {
                if (dp[i - 1, j] == 0 && (c + j) % 3 != c) //特殊处理
                {
                    dp[i, (c + j) % 3] = dp[i - 1, (c + j) % 3];
                }
                else
                {
                    dp[i, (c + j) % 3] = Math.Max(dp[i - 1, (c + j) % 3], dp[i - 1, j] + nums[i - 1]);
                }
            }
        }
        return dp[nums.Length, 0];
    }
}
```