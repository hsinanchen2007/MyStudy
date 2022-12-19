### 解题思路
动态规划

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        int[] dp = new int[n+1] ;
        dp[0] = 0 ;
        dp[1] = 1 ;
        for (int i = 2 ;i <= n ; i++) {
            for (int j = 1 ; j < i ; j ++ ) {
                //因为m > 1 所以计算 d[i] 遍历时要么是 dp[j] * (i - j) 要么 j （不切） * (i -j)
                dp[i] = Math.max(dp[i], (dp[j] > j ? dp[j] : j ) * (i - j)) ;
            }
        }
        return dp[n] ;
    }
}
```