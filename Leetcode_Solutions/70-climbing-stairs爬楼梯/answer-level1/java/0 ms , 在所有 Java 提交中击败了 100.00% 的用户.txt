
```java
class Solution {
    public int climbStairs(int n) {
        int[] dp = new int[n + 2];
        dp[1] = 1;
        dp[2] = 2;//既然这里给了dp[2] 如果传参1，n+1长度是不够的，所以考虑传参1 reutrn掉
        //或者直接dp[n+2]
        for(int i = 3; i < dp.length; ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
}
```