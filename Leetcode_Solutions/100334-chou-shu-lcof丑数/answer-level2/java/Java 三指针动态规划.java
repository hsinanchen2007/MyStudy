### 解题思路
root_2 root_3 root_5分别记录乘2，乘3，乘5的位置。
每一轮循环中，找到对应位置乘对应因子所得结果最小的那一个，记录进入dp[i]，同时将对应的root位置加1
注意：有些时候多个对应位置乘对应因子所得结果相等且均为最小，需要将这些root均加1

### 代码

```java
class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        int root_2 = 0;
        int root_3 = 0;
        int root_5 = 0;
        
        for(int i=1; i<n; i++)
        {
            if(dp[root_2] * 2 ==Math.min(dp[root_2]*2,
               Math.min(dp[root_3]*3,dp[root_5]*5)))
            {
                dp[i] = dp[root_2]*2;
                root_2++;
                if(dp[root_3]*3 == dp[i])
                    root_3++;
                if(dp[root_5]*5 == dp[i])
                    root_5++;
            }
            else if(dp[root_3] * 3 ==Math.min(dp[root_2]*2,
               Math.min(dp[root_3]*3,dp[root_5]*5)))
            {
                dp[i] = dp[root_3]*3;
                root_3++;
                if(dp[root_5]*5 == dp[i])
                    root_5++;
                if(dp[root_2]*2 == dp[i])
                    root_2++;
            }
            else if(dp[root_5] * 5 ==Math.min(dp[root_2]*2,
               Math.min(dp[root_3]*3,dp[root_5]*5)))
            {
                dp[i] = dp[root_5]*5;
                root_5++;
                if(dp[root_3]*3 == dp[i])
                    root_3++;
                if(dp[root_2]*2 == dp[i])
                    root_2++;
            }
        }
        return dp[n-1];

    }
}
```