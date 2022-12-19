### 解题思路
出自某位大佬的题解
https://leetcode-cn.com/problems/edit-distance/solution/dong-tai-gui-hua-java-by-liweiwei1419/

### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
       char [] wordA =word1.toCharArray();
       char [] wordB =word2.toCharArray();
       int [][] dp=new int [word1.length()+1][word2.length()+1];
       dp[0][0]=0;
       int i,j;
        for (i=0;i<dp.length;i++){
            dp[i][0]=i;
        }
        for (j=0;j<dp[0].length;j++){
            dp[0][j]=j;
        }

       for (i=0;i<dp.length-1;i++){
           for (j=0;j<dp[i].length-1;j++){
                if(wordA[i]== wordB[j]){
                   dp[i+1][j+1]=dp[i][j];
                }
                else if(wordA[i]!=wordB[j]){
                    dp[i+1][j+1]=Math.min(Math.min(dp[i+1][j],dp[i][j+1]),dp[i][j])+1;
                }
           }
       }
       return dp[word1.length()][word2.length()];

    }
}
```