### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        // dp[i][j]代表text1[0:i]和text2[0:j]的最长公共子序列数量
        // 当text1[i]==text2[j]时，dp[i][j]=dp[i-1][j-1]
        // 当text1[i]!=text2[j]时，dp[i][j]=max(dp[i-1][j],dp[i][,j-1])
        // 边界：当i=0&&j=0，dp[0][0]=text1[0]==text2[0].
        // 特殊处理，i==0或j==0时：使用多加一行一列空间来处理
        if( text1.length()==0 || text2.length()==0 ) return 0;
        int max=0;
        int[][] dp = new int[text1.length()+1][text2.length()+1]; 
        for( int i=1; i< dp.length; i++ ){
            for( int j=1; j< dp[0].length; j++ ){
                if( text1.charAt(i-1)==text2.charAt(j-1) ){
                    dp[i][j] = dp[i-1][j-1]+1;
                    max = Math.max(max,dp[i][j]);
                } 
                else 
                    dp[i][j]=Math.max( dp[i-1][j],dp[i][j-1] );
            }
        }
        return max;
        
    }
}
```