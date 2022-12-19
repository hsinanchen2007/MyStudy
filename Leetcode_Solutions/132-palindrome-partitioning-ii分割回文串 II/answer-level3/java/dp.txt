### 解题思路
dp

### 代码

```java
class Solution {
    public int minCut(String ss) {
        if (ss == null || ss.length() == 0) {
            return 0;
        }
        char[] s = ss.toCharArray();

        boolean[][] isPalin = calcPalin(s);
        int len = s.length;
        int[] dp = new int[len + 1];
        dp[0] = 0;

        for (int i = 1; i <= len; i++) {
            dp[i] = Integer.MAX_VALUE;
            for (int j = 0; j < i; j++) {
                if(isPalin[j][i - 1]){
                    dp[i] = Math.min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[len] - 1;
    }

    private boolean[][] calcPalin(char[] s) {
        int n = s.length;
        boolean[][] isPalin = new boolean[n][n];

        int i, j, c;
        //odd length
        for (c = 0; c < n; c++) {
            i = j = c;
            while(i >= 0 && j < n && s[i] == s[j]){
                isPalin[i][j] = true;
                i--;
                j++;
            }
        }

        //even length
        for (c = 0; c < n - 1; c++) {
            i = c;
            j = c + 1;
            while(i >= 0 && j < n && s[i] == s[j]){
                isPalin[i][j] = true;
                i--;
                j++;
            }
        }

        return isPalin;
    }
}
```