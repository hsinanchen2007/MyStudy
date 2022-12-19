### 解题思路
这一题和上一题基本一样的代码

### 代码

```java
class Solution {

    public int numWays(int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return 1;
        
        int[] dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        }

        return dp[n];
    }
}
```