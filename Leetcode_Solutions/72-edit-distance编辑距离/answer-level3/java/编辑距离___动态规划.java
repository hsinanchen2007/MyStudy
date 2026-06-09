### 解题思路
此处撰写解题思路
这一题主要是最少问题，所以考虑动态规划来解题。动态规划的核心是将最后的结果存放到dp[i][j]。对于溢出的问题需要增大空间，针对该题dp[i+1][j+1]增加一位防止溢出。
第一步：将两个字符串转换为字符数组，来获取长度进行初始化（在我看来就是在dp的二维数组中固定一维，另一维则存储对应的i或者j值）
第二步：两个for循环同时i与j是从0开始。当判断第i个和第j个字符一样时，进行45度赋值dp[i+1][j+1]=dp[i][j]，如果不等则要进行比较，先进行dp[i+1][j]+1和dp[i][j+1]+1比较最少，其结果再与dp[i][j]+1比最少，最终的结果赋值给dp[i+1][j+1]。
以上是我的个人见解，如有不对还望大佬指点，这也是我第一次做的题和第一次写题解不是很懂。如果有优化的还望指点一下。谢谢
### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
        char[] word1Char = word1.toCharArray()，word2Char = word2.toCharArray();
        int len1 = word1Char.length，len2 = word2Char.length;
        int[][] dp = new int[len1 + 1][len2 + 1];
        for (int i = 1; i <= len1; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= len2; j++) {
            dp[0][j] = j;
        }
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (word1Char[i] == word2Char[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                }else{
                    dp[i + 1][j + 1] = Math.min(Math.min(dp[i + 1][j] + 1, dp[i][j + 1] + 1), dp[i][j] + 1);
                }
            }
        }
        return dp[len1][len2];
    }
}
```