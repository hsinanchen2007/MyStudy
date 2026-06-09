### 解题思路
使用数组dp记录，`dp[i][j]`表示s1的前i个字符和s2的前j个字符能否交错构成s3的前i+j个字符
若s3的前i+j个字符可以由s1的前i个字符和s2的前j个字符交错构成，那么s3的第i+j个字符一定是s1的第i个字符或者s2的第j个字符，且s3的前i+j-1个字符可以由s1的前i-1字符和s2的前j字符，或者s1的前i字符和s2的前j-1字符构成。
如果`dp[i-1][j]==true&&s1[i]==s3[i+j]`，那么s1的前i个字符和s2的前j个字符可以交错构成s3的前i+j个字符；`dp[i][j-1]==true&&s2[j]==s3[i+j]`类似

### 代码

```java
class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        boolean[][] dp = new boolean[s1.length() + 1][s2.length() + 1];
        if(s1.length() + s2.length() != s3.length()) {
            return false;
        }
        for(int i = 0; i <= s1.length(); i++) {
            for(int j = 0; j <= s2.length(); j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = true;
                    continue;
                }
                if(i > 0 && dp[i - 1][j] == true) {
                    if(s1.charAt(i - 1) == s3.charAt(i + j - 1)) {
                        dp[i][j] = true;
                        continue;
                    }
                }
                if(j > 0 && dp[i][j - 1] == true) {
                    if(s2.charAt(j - 1) == s3.charAt(i + j - 1)) {
                        dp[i][j] = true;
                        continue;
                    }
                }
                dp[i][j] = false;
            }
        }
        return dp[s1.length()][s2.length()];
    }

}
```