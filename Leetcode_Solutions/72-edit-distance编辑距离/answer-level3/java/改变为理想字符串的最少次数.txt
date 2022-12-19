### 解题思路
此处撰写解题思路
满足题目条件的操作一共有三种，假设前i-1个字母的改变已经满足最少次数k，则在第i个位置，如果相同则依旧是k，如果不是则有题目所给的那种操作，从中选取操作次数最少的那种操作，因为两个字符串的长度不知，所以应该用二维数组进行动态规划，数组初始化，第一行表示word2的长度为0，则应该初始化为word1的长度可以表示一直进行删除操作，同理第一列也是。
### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
        int len1 = word1.length(), len2 = word2.length();
        int[][] dp = new int[len1+1][len2+1];
        for(int i = 0; i <= len1; i++)
            dp[i][0] = i;
        for(int j = 0; j <= len2; j++){
            dp[0][j] = j;
        }
        for(int i = 1; i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if(word1.charAt(i-1) == word2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1+Math.min(Math.min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
}
```