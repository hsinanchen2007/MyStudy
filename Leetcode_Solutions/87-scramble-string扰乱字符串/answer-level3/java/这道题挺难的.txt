### 解题思路
dp

### 代码

```java
class Solution {
    public boolean isScramble(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();
        if(m != n){
            return false;
        }

        char[] ss1 = s1.toCharArray();
        char[] ss2 = s2.toCharArray();

        boolean[][][] dp = new boolean[n][n][n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][1] = ss1[i] == ss2[j];
            }
        }

        /**
         * f[i][j][k] = OR1<=w<=k-1{f[i][j][w] AND f[i+w][j+w][k-w]} OR
         * OR1<=w<=k-1{f[i][j+k-w][w] AND f[i+w][j][k-w]}
         */
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i < n - k + 1; i++) {
                for (int j = 0; j < n - k + 1; j++) {
                    for (int w = 1; w <= k - 1; w++) {
                        if(dp[i][j][w] && dp[i+w][j+w][k-w]) {
                            dp[i][j][k] = true;
                            break;
                        }
                    }

                    for (int w = 1; w <= k - 1; w++) {
                        if(dp[i][j + k - w][w] && dp[i+w][j][k-w]) {
                            dp[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return dp[0][0][n];
    }
}
```