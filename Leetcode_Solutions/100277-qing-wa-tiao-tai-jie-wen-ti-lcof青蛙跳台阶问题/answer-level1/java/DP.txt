### 解题思路
1.DP自底向上，可以用两个变量优化，使得空间复杂度达到O(1)
2.DP自顶向下，备忘录剪枝，迭代求解。会超时！！！
### 代码

```java
class Solution {
    public int numWays(int n) {
        //DP自下向上
        if(n <= 1){
            return 1;
        }
        int[] dp = new int[n + 1];
        for(int i = 0; i < n + 1; i++){
            dp[i] = 0;
        }
        dp[0] = dp[1] = 1;
        for(int i = 2; i < n + 1; i++){
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        }
        return dp[n];
        
        /*
        dp = new int[n + 1];
        for(int i = 0; i < n + 1; i++){
            dp[i] = 0;
        }
        return getNumWays(n);*/
    }

    /*DP的自顶向下的备忘录解法，不知道为什么超时    
    private int dp[];
    int getNumWays(int n){
        if(n <= 1){
            return 1;
        }
        if(dp[n] != 0){
            return dp[n];
        }
        return (getNumWays(n - 1) + getNumWays(n - 2)) % 1000000007;
    }*/
    
}
}
```