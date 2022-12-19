### 解题思路
动态规划问题
创建二维数组，列的长度为word1的字母长度加1，行的长度为word2字母长度加1
dp[word1.length+1][word2.length+1];
如果word1的i位置字母与word2的j位置字母,dp[i][j] = 1 + Math.min(dp[i][j-1],Math.min(dp[i-1][j],dp[i-1][j-1]));否则dp[i][j] = 1 + Math.min(dp[i][j-1],Math.min(dp[i-1][j],dp[i-1][j-1]-1))。
***
dp[i][j-1] 为 word1 的前 i 个字符和 word2 的前 j - 1 个字符编辑距离的子问题。即对于 word2 的第 j 个字符，我们在 word1 的末尾添加了一个相同的字符，那么 dp[i][j] 最小可以为dp[i][j-1] + 1；
***
dp[i-1][j] 为 word1 的前 i - 1 个字符和 word2 的前 j 个字符编辑距离的子问题。即对于 word1 的第 i 个字符，我们在 word2 的末尾添加了一个相同的字符，那么 dp[i][j] 最小可以为 dp[i-1][j] + 1；
***
dp[i-1][j-1] 为 word1 前 i - 1 个字符和 word2 的前 j - 1 个字符编辑距离的子问题。即对于 word2 的第 j 个字符，我们修改 word1 的第 i 个字符使它们相同，那么 dp[i][j] 最小可以为 dp[i-1][j-1] + 1。特别地，如果 word1 的第 i 个字符和 word2 的第 j 个字符原本就相同，那么我们实际上不需要进行修改操作。在这种情况下，dp[i][j] 最小可以为 dp[i-1][j-1]。
***


### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if(len1 * len2 == 0){
            return len1 + len2;
        }
        int[][] dp = new int[len1+1][len2+1];
        for(int i = 0;i <= len1;i++){
            dp[i][0] = i;
        }
        for(int j = 0;j <= len2;j++){
            dp[0][j] = j;
        }
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(word1.charAt(i-1) != word2.charAt(j-1)){
                    dp[i][j] = 1 + Math.min(dp[i][j-1],Math.min(dp[i-1][j],dp[i-1][j-1]));
                }else{
                    dp[i][j] = 1 + Math.min(dp[i][j-1],Math.min(dp[i-1][j],dp[i-1][j-1]-1));
                }
            }
        }
        return dp[len1][len2];
    }
}
```