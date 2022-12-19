### 解题思路
解题思路已经写在代码的注释中,
1),当t[i]==s[j]时,可以选择使用不使用s[j],然后就分了两种情况.dp[i-1][j-1],dp[i][j-1]
2),当t[i]!=s[j]时,就不能使用s[j]了.

### 代码

```java
/*
 * Copyright (c) 2020
 * @Author:xiaoweixiang
 */


public class Solution {
    public static void main(String[] args) {
        String s = "babgbag";
        String t = "bag";
        int res = numDistinct(s, t);
        System.out.println("res = " + res);
    }


    public static int numDistinct(String s, String t) {
        if ("".equals(s) && "".equals(t)) {
            return 1;
        } else if ("".equals(s)) {
            return 0;
        } else if ("".equals(t)) {
            return 1;
        }
        /**
         * dp[i][j]表示t的前i个字符(包括i)可以由s的前j个字符(包括j)组成的个数
         * dp[i+1][j+1]={
         * 如果t[i+1]==s[j+1],dp[i+1][j+1]=dp[i][j]+dp[i+1][j]
         * 如果t[i+1]!=s[j+1],dp[i+1][j+1]=dp[i+1][j]
         *
         * }
         */
        int[][] dp = new int[t.length()][s.length()];
        for (int i = 0; i < t.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                if (t.charAt(i) == s.charAt(j)) {
                    if (i == 0 && j == 0) {
                        dp[i][j] = 1;
                    } else if (i > 0 && j > 0) {
                        dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                    } else if (i == 0 && j > 0) {
                        // 最后一位有两种选择
                        dp[i][j] = dp[i][j - 1] + 1;
                    } else if (i > 0 && j == 0) {
                        dp[i][j] = 0;
                    }
                } else {
                    if (j > 0) {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
            }
        }
        return dp[t.length() - 1][s.length() - 1];
    }
}

```