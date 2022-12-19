### 解题思路
定义dp[i]的含义是目标值target = i的时候，其和乘积的最大值，因为要求到第i个数，所以直接将dp[]的长度设置为i + 1，最后直接返回dp[target]即可。这里要最特别注意到，动态递推方程，每次都需要才从dp[1]开始，相当于先确定一个数j（j < i），然后和dp[i - j]的乘积即为本次组合的乘积最大值。

### 代码

```java
class Solution {
    public int integerBreak(int target) {
        int[] dp = new int[target + 1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for ( int i = 3; i <= target; i ++){
            for (int j = 1; j < i; j ++){
                dp[i] = Math.max(dp[i], Math.max(dp[i - j] * j, j * (i - j)));
            }
        }
        
        return dp[target];
    }
}
```