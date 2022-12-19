### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numWays(int n) {
        if(n == 0){
            return 1;
        }
        long[] dp = new long[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]%1000000007 + dp[i-2]%1000000007;
        }
        return (int)(dp[n]%1000000007);
    }
}
```