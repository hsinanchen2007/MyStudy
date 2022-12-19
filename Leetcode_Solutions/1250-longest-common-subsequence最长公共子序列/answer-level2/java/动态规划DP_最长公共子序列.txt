![image_1568826071.png](https://pic.leetcode-cn.com/1672e09577389fce82fa70e31ad93bdc149ac4400ddced2aacf5820fb83b9860-image_1568826071.png)
咱们就以如上图所示的例子来进行最长子序列的分析，其中两个子序列分别为：“XMJYAUZ”和“MZJAWXU”；要想求出两个字符串的最长子序列，用二维数组(dp)进行求解。数组中的值代表当前字符以及当前字符之前所确定的子序列，那我们来看看该数组的值是**如何确定的(以dp[2][1]的值举例)？**
（1）如果dp[2][1]的值匹配那么dp[2][1] = dp[?][?] + 1; *dp[?][?]*一定是出去该处的字符，也就是该字符之前的公共最长子序列，那就是dp[1][0]处的值。
（2）如果dp[2][1]的值没有匹配那么dp[2][1] = max(dp[1][1], dp[2][0]);

**终上所述我们的dp方程也已经找到了：dp[i + 1][j + 1] = 1 + dp[i][j]或者是dp[i + 1][j + 1] = max(dp[i][j+1], dp[i+1][j])**

代码如下：
```
    public static int longestCommonSubsequence(String s1, String s2) {
        int[][] dp = new int[s1.length() +1][s2.length() + 1];
        for (int i = 0; i < s1.length() + 1; i++) {
            for (int j = 0; j < s2.length(); j++) {
                if (s1.charAt(i) == s2.charAt(j)) dp[i + 1][j +1] = 1 + dp[i][j];
                else dp[i + 1][j + 1] = Math.max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[s1.length()][s2.length()];
    }
```

