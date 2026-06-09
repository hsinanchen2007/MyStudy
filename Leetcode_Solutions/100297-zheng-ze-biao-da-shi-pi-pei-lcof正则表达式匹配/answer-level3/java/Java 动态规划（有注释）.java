### 解题思路
自底向上的动态规划，具体思路见代码注释。

### 代码

```java
class Solution {
    public boolean isMatch(String s, String p) {
        char[] str = s.toCharArray();
        char[] pstr = p.toCharArray();
        int sLen = str.length, pLen = pstr.length;
        boolean[][] dp = new boolean[sLen + 1][pLen + 1];
        dp[sLen][pLen] = true;
        for (int i = sLen; i >= 0; i --) {
            // 当 i = sLen 时，即在判断 p[j:] 是否与空串匹配
            for (int j = pLen - 1; j >= 0; j --) {
                // 判断当前位置的字符是否匹配
                boolean isCurMatch = i < sLen && (str[i] == pstr[j] || pstr[j] == '.');
                // 如果 p[j + 1] 为 '*'，则需要看：
                // 1. p[j + 2] 和 s[i:] 是否匹配，若匹配，则 p[j:] 一定匹配
                //   （因为'*'可以无效化前面的字母）
                // 2. 若当前位置的字符匹配，则看 p[j:] 与 s[i + 1] 是否匹配，若匹配，则一定匹配。
                //   （因为'*'可以重复前面的字母）
                if (j + 1 < pLen && pstr[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || isCurMatch && dp[i + 1][j];
                }
                // 否则，则看当前是否匹配，以及 p[j + 1] 和 s[i + 1] 是否匹配
                else {
                    dp[i][j] = isCurMatch && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
}
```