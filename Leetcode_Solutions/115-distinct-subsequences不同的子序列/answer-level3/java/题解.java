### 解题思路
这道题卡了我一个下午，其实并不难，关键在于你要拿张纸画一画，把s作为横轴，t作为纵轴，一目了然，我就是因为一开始拍脑瓜写了个半对的状态方程上去，结果后面改来改去改不对，最后发现是i，j位置写反了，真的吐了，做题思路清晰很重要，特别是动态规划的题，想清楚了在🐎代码很重要，不要想到哪写到哪

### 代码

```java
class Solution {
    public int numDistinct(String s, String t) {
        if (s.length() == 0) {
            return 0;
        }
        if (t.length() == 0) {
            return 1;
        }
        int len = s.length();
        int len1 = t.length();
        int[][] dp = new int[len1][len];

        if (s.charAt(0) == t.charAt(0)) {
            dp[0][0] = 1;
        }
        for (int i = 1; i < len; i++) {
            if (s.charAt(i) == t.charAt(0)) {
                dp[0][i] = dp[0][i - 1] + 1;
            } else {
                dp[0][i] = dp[0][i - 1];
            }
        }

        for (int i = 1; i < len1; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i < len1; i++) {
            for (int j = 1; j < len; j++) {
            
                if (t.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[len1 - 1][len - 1];
    }
}
```