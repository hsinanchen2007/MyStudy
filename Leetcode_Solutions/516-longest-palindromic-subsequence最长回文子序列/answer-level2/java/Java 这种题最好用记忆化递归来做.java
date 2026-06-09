### 解题思路
这种题top-down方法要简单的多，只需要知道结束递归的条件

理解递归公式即可

### 代码

```java
class Solution {
    int[][] dp;
    int n;
    String s;
    public int longestPalindromeSubseq(String s) {
        this.n = s.length();
        this.s = s;
        dp = new int[n][n];
        return backtrack(0, n - 1);
    }

    int backtrack(int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] > 0) return dp[i][j];
        if (s.charAt(i) == s.charAt(j)) {
            return dp[i][j] = 2 + backtrack(i + 1, j - 1);
        }
        return dp[i][j] = Math.max(backtrack(i + 1, j), backtrack(i, j - 1));
    }
}
```