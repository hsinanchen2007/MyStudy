### 解题思路
此处完美解答这个问题
https://zhuanlan.zhihu.com/p/107847935

### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
        int length1 = word1.length();
            int length2 = word2.length();
            int[][] dp = new int[length1 + 1][length2 + 1];
            //初始化base case
            for (int i = 1; i <= length1; i++) {
                dp[i][0] = dp[i - 1][0] + 1;
            }
            for (int j = 1; j <= length2; j++) {
                dp[0][j] = dp[0][j - 1] + 1;
            }
            //填充二维数组dp表
            for (int i = 1; i <= length1; i++) {
                for (int j = 1; j <= length2; j++) {
                    if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = Math.min(Math.min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                    }
                }
            }
            return dp[length1][length2];
    }
}
```