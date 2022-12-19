思路在代码中体现
```java
class Solution {
    public int numDistinct(String s, String t) {
        int[][] dp = new int[t.length() + 1][s.length() + 1];

        //base case：
        //空串的任意子序列不能匹配任意字符串
        for(int i = 0; i < dp.length; i++) dp[i][0] = 0;
        //空串可以被任意字符串的一个空串子串匹配
        for(int i = 0; i < dp[0].length; i++) dp[0][i] = 1;

        /**
        * dp program :
        * 如果当前字符相等，那么：
        * dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1]
        * 含义： 已经可以与当前字符串匹配的个数：dp[i][j - 1]
        * 因为当前字符的相等新增匹配个数：dp[i - 1][j - 1]
        * dp[i][j] = dp[i][j - 1]
        */
        for(int i = 1; i < dp.length; i++) {
            for(int j = 1; j < dp[0].length; j++) {
                if(t.charAt(i - 1) == s.charAt(j - 1)) 
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                else dp[i][j] = dp[i][j - 1];
            }
        }

        return dp[dp.length - 1][dp[0].length - 1];
    }
}
```
