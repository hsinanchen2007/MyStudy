### 解题思路
```text
动态规划
1. dp[i][j]表示word1的前i位转换为word2前j位需要的最短距离, 对应的最后一位的下标为word1[i-1]，word2[j - 1]
2. 初始化dp[i][j], dp[i][0] = i(删), dp[0][j] = j(增);
3. 循环，状态转移方程：dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1
4. dp[word1.length][word2.length]即为最终结果

状态转移方程：dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1
状态转移方程推导过程如下，以官方例子为例：
增：设horse -> ro距离为x，则horse -> ros的距离小于等于x + 1 （horse先转换为ro，ro再增一个s，即x+1）
删：设hors -> ros的距离为x，则horse -> ros的距离小于等于x + 1 （horse先去掉e，再转换为ros，即1+x）
替：设hors -> ro的距离为x，则horse -> ros的距离小于等于x + 1 （hors先转换为ro，e替换为s，即x+1）
```

### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
        // dp[i][j]表示word1前i个字母转换成word2前j个字母需要的最短距离
        int[][] dp = new int[word1.length() + 1][word2.length() + 1];
        // 初始化
        for (int i = 0; i < word1.length() + 1; i++) {
            // word1的前i位转换成word2的前0位（word2为空）
            dp[i][0] = i;
        }
        for (int i = 0; i < word2.length() + 1; i++) {
            // word1的前0位（word1为空）转换成word2的前i位
            dp[0][i] = i;
        }
        for (int i = 1; i < word1.length() + 1; i++) {
            for (int j = 1; j < word2.length() + 1; j++) {
                // 如果word1的第i位(word1[i - 1])，与word2的第j位（word2[j - 1]）相等
                // 则dp[i][j] = dp[i - 1][j - 1]
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (word1.charAt(i - 1) != word2.charAt(j - 1)) {
                    dp[i][j] = Math.min(dp[i][j-1], Math.min(dp[i-1][j], dp[i-1][j-1])) + 1;
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }
}
```

### 测试用例
```java
public class SolutionTest {
    Solution solution = new Solution();

    @Test
    public void minDistance() {
        String word11 = "horse", word12 = "ros";
        int expect1 = 3;
        int result1 = solution.minDistance(word11, word12);

        assertEquals(expect1, result1);

        String word21 = "intention", word22 = "execution";
        int expect2 = 5;
        int result2 = solution.minDistance(word21, word22);

        assertEquals(expect2, result2);
    }
}
```