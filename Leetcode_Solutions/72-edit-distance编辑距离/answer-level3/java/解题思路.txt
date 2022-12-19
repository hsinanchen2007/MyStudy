### 解题思路
- 解法：
  - 使用DP数组，DP[i][j]代表**word1**到**i**位置转换成**word2**到**j**位置需要几步。
  - 因此当计算的时候会出现两种情况：
  - 当word1[i] == word2[j]的时候，dp[i][j] = dp[i-1][j-1]
  - 当word1[i] != word2[j]的时候,需要考虑 
    -  **[插入]** **[删除]** **[替换]** 这三种操作最短的次数
    - **[插入]** dp[i][j-1]代表word1[i]和word2[j-1]是相等的，这时word1[i]插入一个值可以变为word2[j]
    - **[删除]** dp[i-1][j]代表word1[i-1]和word2[j]是相等的，这时word1[i]删除一个值可以变为word2[j]
    - **[替换]** dp[i-1][j-1]代表word1[i-1]和word2[j-1]相等，这时word1[i]替换一个值可以变为word2[j]替换操作
  -  **dp[i][j] = min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1])+1**
- 题目要求是从word1到word2进行变化，word1是可以变化的，word2是不可以变化的，

### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        int[][] dp = new int[n1+1][n2+1];
        // 第一行
        for (int j = 1; j <= n2; j++) dp[0][j] = dp[0][j-1] + 1;
        // 第一列
        for (int i = 1; i <= n1 ; i++) dp[i][0] = dp[i-1][0] + 1;

        for (int i = 1; i <= n1 ; i++) {
            for (int j = 1; j <= n2 ; j++) {

                if (word1.charAt(i-1) == word2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1];
                }else {
                    dp[i][j] = Math.min(Math.min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]) + 1;
                }

            }

        }

        return dp[n1][n2];
    }
}
```