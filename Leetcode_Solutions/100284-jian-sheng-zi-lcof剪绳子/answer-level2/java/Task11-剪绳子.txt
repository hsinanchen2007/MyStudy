### 解题思路
首先的思路是进行递归，但是递归耗时太长，所以需要将递归过程记忆化或者使用动态规划。

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        // 递归，会超时
        // if (n <= 2) {
        //     return 1;
        // }

        // int result = 1;
        // for (int i = 1; i < n; i++) {
        //     result = Math.max(result, Math.max(i * cuttingRope(n - i), i * (n-i)));
        // }

        // return result;

        //动态规划，其实就是将递归过程记忆化。
        int[] dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = Math.max(dp[i], Math.max(j * dp[i - j], j * (i -j)));
            }
        }
        return dp[n];


        

      

    }
}
```