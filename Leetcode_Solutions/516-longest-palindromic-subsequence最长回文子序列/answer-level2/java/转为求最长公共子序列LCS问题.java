### 思路
- 原题相当于，原字符串s与倒置后所得字符串 _s，计算两个字符串的最长公共子序列。

Tip:必须用 `dp[1...n1][1...n2]`来存储公共子序列长度，边界默认为 0，否则的话在 `i-1` 和 `j-1` 关于 0 的边界处处理起来略复杂。

### 代码
```
public int LCS(String s1, int n1, String s2, int n2) {
    // 递归
    int[][] dp = new int[n1 + 1][n2 + 1];
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n1][n2];
}

public int longestPalindromeSubseq(String s) {
    int len = s.length();
    String _s = new StringBuffer(s).reverse().toString();
    return LCS(s, len , _s, len );
}
```
### 总结
时间复杂度 $O(n^2)$，空间复杂度$O(n^2)$;