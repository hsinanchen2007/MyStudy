### 解题思路
根据注解，背包问题

### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
        int l1=word1.length();
        int l2=word2.length();
        int[][] dp=new int[l1+1][l2+1];
        for(int i=1;i<=l1;i++)dp[i][0]=dp[i-1][0]+1;
        for(int j=1;j<=l2;j++)dp[0][j]=dp[0][j-1]+1;
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(word1.charAt(i-1)==word2.charAt(j-1))dp[i][j]=dp[i-1][j-1];//charAt(i-1)/(j-1)表示的是word里面的字符位置，从下标0开始，而dp[i][j]表示的是字符0-i与字符0-j匹配的最小值，刚好二者差了1，因为一开始dp初始化的时候0行0列是置空的。
                else{
                    dp[i][j]=Math.min(Math.min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
                }
            }
        }
        return dp[l1][l2];
    }
}
```