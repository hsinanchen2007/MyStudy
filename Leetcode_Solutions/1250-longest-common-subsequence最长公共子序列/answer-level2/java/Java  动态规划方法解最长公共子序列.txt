### 解题思路
设dp[i][j]为字符串text1和text2的最长公共子序列，那么递推有3种情况
1. 如果text1[i] == text2[j]，说明最后两个字符相同，则dp[i][j] = dp[i-1][j-1] + text1[i]
2. 否则，dp[i][j]就应该等于分别去掉两个字符串的尾部字符后的公共子序列中的大者
    - 即如果len(dp[i-1][j]) >= len(dp[i][j-1])，则dp[i][j] = dp[i-1][j]，此时就暗含了去掉text1的字最后一个字符对计算结果无影响
    - 否则len(dp[i][j]) = len(dp[i][j-1])，此时就暗含了去掉text2的字最后一个字符无影响

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
### 时间复杂度
O(m*n)
### 空间复杂度
O(m*n)
