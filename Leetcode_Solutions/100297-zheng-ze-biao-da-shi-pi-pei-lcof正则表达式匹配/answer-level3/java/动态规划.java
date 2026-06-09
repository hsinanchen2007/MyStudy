使用动态规划自底向上方法。
定义`boolean[][] dp = new boolean[s.length() + 1][p.length() + 1]`，初始化`dp[s.length()][p.length()] = true`，表示当两者都为空时匹配。
如何得到`dp[i][j]`的值？首先判断`s.charAt(i)`和`p.charAt(j)`是否匹配，匹配的条件是两个字符相同，或者`p.charAt(j)`是`'.'`。然后判断`p.charAt(j + 1)`是不是`'*'`，若是，由于`'*'`可匹配0个字符，当`dp[i][j + 2] == true`时`dp[i][j] = true`，另外当目前的字符匹配且`d[i + 1][j] == true`时`dp[i][j] = true`。
如果`p.charAt(j + 1)`不是`'*'`，则`dp[i][j] = true`当且仅当目前的字符匹配且`dp[i + 1][j + 1] == true`。
最后返回`dp[0][0]`。
```
class Solution {
    public boolean isMatch(String s, String p) {
        int sLength = s.length(), pLength = p.length();
        boolean[][] dp = new boolean[sLength + 1][pLength + 1];
        dp[sLength][pLength] = true;
        for (int i = sLength; i >= 0; i--) {
            for (int j = pLength - 1; j >= 0; j--) {
                boolean charMatch = i < sLength && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.');
                if (j < pLength - 1 && p.charAt(j + 1) == '*')
                    dp[i][j] = dp[i][j + 2] || charMatch && dp[i + 1][j];
                else
                    dp[i][j] = charMatch && dp[i + 1][j + 1];
            }
        }
        return dp[0][0];
    }
}
```
