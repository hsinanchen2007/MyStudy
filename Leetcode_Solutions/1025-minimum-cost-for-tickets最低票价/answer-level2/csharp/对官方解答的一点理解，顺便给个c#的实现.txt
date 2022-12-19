
DP(i)我觉得应该加一点解释，定义为**在没有任何通行证生效时**，从第i天开始计划买票所需的最小花费。这么想问题会方便很多。

```

public class Solution {

    static readonly int[] timeLongList = {1,7,30};

    public int MincostTickets(int[] days, int[] costs) 
    {
        int[] dp = new int[366];

        int start = days[days.Length - 1];

        int targetIndex = days.Length - 1;
        for(int i = start; targetIndex >= 0; i--)
        {
            int target = days[targetIndex];

            if(i != target)
            {
                dp[i] = dp[i + 1];
                continue;
            }

            //dp(i) = Min(cost[0] + dp(i + 1), cost[1] + dp(i + 7), cost[2] + dp(i + 30))
            dp[i] = int.MaxValue;
            for(int j = 0; j < 3;j++)
            {
                int cost = 0;
                if( i + timeLongList[j] <= start)
                {
                    cost = dp[i + timeLongList[j]];
                }
                dp[i] = Math.Min(dp[i], cost + costs[j]);
            }

            targetIndex -= 1;    
        }

        return dp[days[0]];
    }
}
```

内存其实完全没有用到366，还有再优化的空间。

