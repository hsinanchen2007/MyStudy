```
class Solution {
    public int minDistance(String word1, String word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        char[] char1 = word1.toCharArray();
        char[] char2 = word2.toCharArray();
        int[][] dp = new int[len1+1][len2+1];
        // 当min(i,j)==0时候,即有一个串为空时候,dp[i][j]=max(i,j)
        for(int i=1;i<=len1;i++){
            dp[i][0]=i;
        }
        // 当min(i,j)==0时候,即有一个串为空时候,dp[i][j]=max(i,j)
        for(int j=1;j<=len2;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                int d = 0;
                if(char1[i-1]!=char2[j-1]){ // 判断word1第i个元素和word2第j个元素,是否相等
                    d=1;
                }
                // 删除ai,插入bj,ai替换bj
                dp[i][j]=Math.min(dp[i-1][j]+1,Math.min(dp[i][j-1]+1,dp[i-1][j-1]+d));
            }
        }
        return dp[len1][len2];
    }
}
```
