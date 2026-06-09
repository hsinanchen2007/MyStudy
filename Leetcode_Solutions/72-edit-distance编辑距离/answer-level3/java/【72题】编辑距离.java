**题意分析**
(1) 将字符串 word1 转换成 word2，计算最少操作数。
(2) 每次只能插入、删除或替换一个字符。

**方法一：动态规划**
思路：
(1) 一个字符串转换为另一个字符串，每一步转换都可以有多种操作方式。
(2) 题目要求最少操作次数，因此可以记录每一步转换的最少操作次数从而使得最终操作数最少。

定义动态数组 dp ：
dp[i][j]表示 word1 第 i 个字符及之前字符串转为 word2 第 j 个字符及之前字符串需要的最少操作数。
*** 需要注意的对动态数组的定义以及初始化边界值。
```
class Solution {
    public int minDistance(String word1, String word2) {
        if (word1.equals(word2)) {
            return 0;
        }
        int len1 = word1.length();
        int len2 = word2.length();
        // word1 或者 word2 为空串的情况。
        if (len1 * len2 == 0) {
            return len1 + len2;
        }
        // dp 数组记录 word1 前 i 个字符变成 word2 前 j 个字符的操作次数。
        int[][] dp = new int[len1 + 1][len2 + 1];
        // 初始化边界状态，当 word2 为空串，则 word1 每个字符需要删除一次。
        for (int i = 1; i <= len1; i++) {
            dp[i][0] = i;
        }
        // 初始化边界状态，当 word1 为空串，则 word1 需要插入 word2 的每个字符一次。
        for (int j = 1; j <= len2; j++) {
            dp[0][j] = j;
        }
        // 遍历得到 word1 所有位置变化到 word2 所有位置需要的操作次数。
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                // 如果新遍历到的 word1 字符和新遍历到的 word2 字符一样则不需要操作。
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                    continue;
                }
                // 一次操作： word1 删除第 i 个字符。
                int delete = dp[i - 1][j] + 1;
                // 一次操作： word1 在第 i 个字符之后插入 word2 第 j 个字符。
                int insert = dp[i][j - 1] + 1;
                // 一次操作： word1 第 i 个字符替换为 word2 第 j 个字符。
                int replace = dp[i - 1][j - 1] + 1;
                dp[i][j] = Math.min(delete, Math.min(insert, replace));
            }
        }
        return dp[len1][len2];
    }
}
```
