### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestCommonSubsequence(String s, String substr) {
        int m=s.length();
        int n=substr.length();
        /**
         * dp代表：dp[i,j] 代表s[1:i]和代表substr[1:j]的最长公共序列
         */
        int[][] dp = new int[m + 1][n + 1];
        //dp[0,0] 代表空串
        for(int i=1;i<=m;i++){    
            for(int j=1;j<=n;j++){
                if (s.charAt(i - 1) == substr.charAt(j - 1)) {
                  //当s[i]和substr[j]是公共子序列时，应该dp[i-1,j-1]基础之上+1
                    dp[i][j]=dp[i-1][j-1]+1;
                }else {
                 //s[i]和substr[j]至少有一个不是公共子序列时,应该从左边或者上面取最长的一个作为s[i]和substr[j] 
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
}
```