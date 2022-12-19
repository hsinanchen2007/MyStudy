### 解题思路
 开始思路：
    dp[i][j]=max{dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+(s1.charAt(i) == s2.charAt(j) ? 1 : 0)} (i>0&&j>0)
    dp[0][0]=s1.charAt(i) == s2.charAt(j) ? 1 : 0;  (i==0||j==0)
    dp[i][j]=max{dp[i][j-1],s1.charAt(i) == s2.charAt(j)}  (i==0,j>0)
    dp[i][j]=max{dp[i-1][j],s1.charAt(i) == s2.charAt(j)}  (j==0,i>0)
 
  优化后的
   dp[i][j]=0 (i==0||j==0)
   dp[i][j]=dp[i-1][j-1]+1; (s1[i]==s2[j])
   dp[i][j]=max{dp[i-1][j],dp[i][j-1]} (s1[i]!=s2[j])

### 代码

```java
class Solution {
//动态规划 迭代方式
    public int longestCommonSubsequence(String text1, String text2) {
        if (text1.length() == 0 || text2.length() == 0)
            return 0;
        int m = text1.length(), n = text2.length();
        int[][] dp = new int[m + 1][n + 1];
        char[] s1 = text1.toCharArray();
        char[] s2 = text2.toCharArray();

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
}

```