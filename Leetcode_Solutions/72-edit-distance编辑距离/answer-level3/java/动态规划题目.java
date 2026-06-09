### 解题思路
参考powcai哥的思路

### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
        //动态规划题目
        //定义dp数组 dp[i][j] 表示word1 i 到word2 j的所需要的编辑距离
        //如果 word1[i] == word2[j] dp[i][j] = dp[i-1][j-1]
        //如果 word1[i] != word2[j] 分为三种情况 替换 dp[i-1][j-1] 删除dp[i-1][j] 插入 dp[i][j-1]

        //word1长度
        int d1 = word1.length();
        //word2长度
        int d2 = word2.length();
        //定义dp数组
        int[][] dp = new int[d1 + 1][d2 + 1];

        //行 word1为空 word2 不为空 插入操作
        for (int i = 1; i < d2 + 1; i++) {
            dp[0][i] = dp[0][i-1] + 1;
        }

        //列 word1不为空 word2 为空 删除操作
        for (int i = 1; i < d1 + 1; i++) {
            dp[i][0] = dp[i-1][0] + 1;
        }

        //二维数组dp
        for (int i = 0; i < d1; i++) {
            for (int j = 0; j < d2; j++) {
                if (word1.charAt(i) == word2.charAt(j)) {
                    dp[i+1][j+1] = dp[i][j];
                } else {
                    dp[i+1][j+1] = Math.min(Math.min(dp[i][j], dp[i][j+1]), dp[i+1][j]) + 1;
                }
            }
        }

        return dp[d1][d2];
    }
}
```