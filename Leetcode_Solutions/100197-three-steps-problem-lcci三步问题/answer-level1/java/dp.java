### 解题思路
对数取模的正确写法 谨记
((dp[k-1] % 1000000007 + dp[k-2] % 1000000007) % 1000000007 + dp[k-3] % 1000000007) % 1000000007

### 代码

```java
class Solution {
    public int waysToStep(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 4;
        int[] dp = new int[n+1];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int k = 4;k <= n; k++){
            dp[k] = ((dp[k-1] % 1000000007 + dp[k-2] % 1000000007) % 1000000007 + dp[k-3] % 1000000007) % 1000000007;
        }
        return dp[n];
    }
}
```