### 解题思路
爬下一层台阶有两种方法，当前+1,或者之前+2，也即dp[i] = dp[i-1] + dp[i-2]

### 代码

```java
class Solution {
    public int numWays(int n) {
        if(n < 0) return -1;
        if(n == 0 ||n == 1) return 1;
        if(n == 2) return 2;
        double mod = 1e9 + 7;
        double[] dp = new double[n];
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2;i<n;i++)
            dp[i] = (dp[i-1] + dp[i-2])%(1e9 + 7);
        return (int)dp[n-1];
    }
}
```