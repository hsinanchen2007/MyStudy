本来这题是没有思路的，有点像求两个字符串的重复子序列，但是又不一样，看了题目下面的类似题目，都是中等难度，有`1035. 不相交的线`，`583. 两个字符串的删除操作`，`712. 两个字符串的最小ASCII删除和`，一题题地做完发现这题也会了。。。和我一样看到困难题就有点懵地同学可以试试做相似题，逐步递进；   
这题和`712. 两个字符串的最小ASCII删除和`非常像，这题还简单一丢丢        
```java
class Solution {
    public int minDistance(String word1, String word2) {
        //dp[i][j]表示从word1[:i]修改为word[:j]操作的次数；
        //如果word1[i]==word2[j]，则dp[i][j] = dp[i-1][j-1]
        //否则取dp[i-1][j-1],dp[i][j-1],dp[i-1][j]最小值加1
        int len1 = word1.length(), len2 = word2.length();
        int[][] dp = new int[len1+1][len2+1];
        for(int i=1;i<=len1;i++){
            dp[i][0] = i;
        }
        for(int j=1;j<=len2;j++){
            dp[0][j] = j;
        }
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(word1.charAt(i-1)==word2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = Math.min(dp[i-1][j-1],Math.min(dp[i][j-1],dp[i-1][j]))+1;
                }
            }
        }
        return dp[len1][len2];
    }
}
```