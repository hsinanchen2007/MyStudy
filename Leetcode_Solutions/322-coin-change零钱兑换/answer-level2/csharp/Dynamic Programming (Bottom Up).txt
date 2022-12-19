### 解题思路
I did not figure out the solution to be honest, I just borrowed the 3rd solution from the official solution, and change the syntax from Java to C#.

### 代码

```csharp
public class Solution {
    public int CoinChange(int[] coins, int amount) 
    {
        // Acknowledgement: https://leetcode-cn.com/problems/coin-change/solution/322-ling-qian-dui-huan-by-leetcode-solution/

        int max = amount + 1;
        int[] dp = new int[max];
        Array.Fill(dp, max);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.Length; j++)
            {
                if (coins[j] <= i)
                {
                    dp[i] = Math.Min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
}
```