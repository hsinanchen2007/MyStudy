### 解题思路
    1. 运用DP的思路进行解答。首先列出能够满足该题DP的一套逻辑：
       逻辑是除了n < 4，其余满足 dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
    2. 注意是结果dp[i]存的是取余后的。

### 代码

```java
class Solution {
    public int waysToStep(int n) {
        long[] dp = new long[n + 3];
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i < (n + 3); i++) {
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000007L;
        }
        return (int) dp[n + 2];
    }
}
```