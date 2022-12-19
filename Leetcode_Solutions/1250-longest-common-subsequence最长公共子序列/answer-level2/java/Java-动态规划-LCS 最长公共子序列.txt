### 解题思路
该问题其实就是父问题和子问题的关系，可以考虑采用动态规划算法。

记状态转移二维数组dp[i][j]表示从 字符串text1中下标 0到i-1 和 字符串text2中0到j-1 的最长公共子序列。

设dp[i][j]为字符串text1和text2的最长公共子序列，那么递推有3种情况，经过推导可以得出状态转移方程如下：

- 如果text1[i] == text2[j]，说明最后两个字符相同
`dp[i][j] = dp[i-1][j-1] + text1[i-1]`

- 否则，dp[i][j]就应该等于分别去掉两个字符串的尾部字符后的公共子序列中的大者

	- 即如果len(dp[i-1][j]) >= len(dp[i][j-1])，则dp[i][j] = dp[i-1][j]，此时就暗含了去掉text1的字最后一个字符对计算结果无影响
		`dp[i][j] = dp[i-1][j]`

	- 否则len(dp[i][j]) = len(dp[i][j-1])，此时就暗含了去掉text2的字最后一个字符无影响
	`dp[i][j] = dp[i][j-1]`

从1到len遍历两个字符串，最终得到的 dp[len_text1][len_text2]便是最终结果，代表字符串a和字符串b的最长公共子序列。

以下代码为了方便，数组dp[1][1]代表两个字符串首字符的公共子序列，而不是从0开始。

### 代码

```java
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int[][] dp = new int[text1.length()+1][text2.length()+1];
        for(int i = 1; i <= text1.length(); i ++)
            for(int j = 1; j <= text2.length(); j ++)
                dp[i][j] = text1.charAt(i-1) == text2.charAt(j-1) ? dp[i][j] =  dp[i-1][j-1] + 1 : Math.max(dp[i][j-1], dp[i-1][j]);
        return dp[text1.length()][text2.length()];
    }
}
```