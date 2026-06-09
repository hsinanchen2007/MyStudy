### 解题思路
第一种思路：
 dp为二维数组，dp[i][j]
i 表示 当前排列的长度， j表示当前排列的结束数字是j
则 
当S.charAt(i - 1) == 'D'的时候 dp[i][j] += dp[i - 1][k] for k in j to i - 1
当S.charAt(i - 1) == 'I'的时候 dp[i][j] += dp[i - 1][k] for k in 0 to j - 1
```java
class Solution1 {
    public int numPermsDISequence(String S) {
        int n = S.length();
        int mod = 1000000007;
        int[][] dp = new int[n + 1][n + 1];
        // dp[i][j] means the num of permutation with length i, and end with number j;
        dp[0][0] = 1;
        for (int i = 1;i <= n; i ++) {
            for (int j = 0; j <= i; j++) {
                if (S.charAt(i - 1) == 'D') {
                    for (int k = j; k <= i - 1; k++) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                    }
                } else {
                    for (int k = 0; k < j; k ++) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                    }
                }
            }            
        }
        int res = 0;
        for (int i = 0; i <= n; i++) {
            res += dp[n][i] % mod;
            res %= mod;
        }
        return res;
    }
}
```
第二种思路：
 dp为二维数组，dp[i][j]
i 表示 当前排列的长度， j表示当前排列的结束数字是j + 1小的
则 
当S.charAt(i - 1) == 'D'的时候 dp[i][j] = sum(dp[i - 1][k]) for k in j  to n - 1
当S.charAt(i - 1) == 'I'的时候 dp[i][j] = sum(dp[i - 1][k]) for k in 0 to j
```java
class Solution {
    public int numPermsDISequence(String S) {
        int n = S.length();
        int mod = 1000000007;
        int[][] dp = new int[n + 1][n + 1];
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        for (int i = 0; i < n; i ++ ) {
            if (S.charAt(i) == 'D') {
                int cur = 0 ;
                for (int j = n - i - 1; j >= 0; j --) {
                    cur += dp[i][j + 1];
                    cur %= mod;
                    dp[i + 1][j] = cur;
                }
            } else {
                int cur = 0;
                for (int j = 0; j < n - i; j ++) {
                    cur += dp[i][j];
                    cur %= mod;
                    dp[i + 1][j] = cur;
                }
            }
        }
        return dp[n][0];        
    }
}
```