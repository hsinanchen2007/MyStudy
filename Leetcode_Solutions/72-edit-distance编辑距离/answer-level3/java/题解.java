### 解题思路
动态规划，从两个字符串的尾部开始判断，使用递归判断每一种情况的优劣，用备忘录进行优化

### 代码

```java
class Solution {

    public int minDistance(String word1, String word2) {
        int[][] dp = new int[word1.length() + 1][word2.length() + 1];
        for (int i = 0; i < word1.length(); i++) {
            for (int j = 0; j < word2.length(); j++) {
                dp[i][j] = -1;
            }
        }
        return work(word1.length() - 1, word2.length() - 1, word1, word2, dp);
    }

    int work(int i, int j, String word1, String word2, int[][] dp) {
        if (i == -1) {
            return j + 1;
        } 
        if (j == -1) {
            return i + 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (word1.charAt(i) == word2.charAt(j)) {
            dp[i][j] = work(i - 1, j - 1, word1, word2, dp);
            return dp[i][j];
        } else {
            dp[i][j] =  Math.min(
                // 删除
                work(i - 1, j, word1, word2, dp) + 1,
                Math.min(
                    // 替换
                    work(i - 1, j - 1, word1, word2, dp) + 1,
                    // 插入
                    work(i, j - 1, word1, word2, dp) + 1
                )
            );
            return dp[i][j];
        }
    }

}
```