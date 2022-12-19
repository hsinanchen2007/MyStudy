### 解题思路
![image.png](https://pic.leetcode-cn.com/247b8efb3561def1708c3081dc6a5421cdecd2d14233ee461897d2f0a25bc910-image.png)

经典的动态规划，

## 定义dp：
dp[i][j]：表示word1串前i与word2串前j的编辑距离。

## 考虑初始化：
显然dp[0][0] = 0，因为空串
显然，dp[i][0]表示word1前i与word2空串，所以dp[i][0]就是word1的长度
同理，dp[0][i]也是如此

## 转移方程：
我们当前求的是dp[i][j]:
1) 如果第i与第j个字符相等，这时候看前面i-1与j-1的编辑距离，所以dp[i][j] = dp[i-1][j-1]
2) 否则有可能从下面几种情况转换过来：（取最优：最小值）
- dp[i][j] = dp[i-1][j] + 1 表示删除word1第i个字符，所以是前i-1与j的距离+1
- dp[i][j] = dp[i][j-1] + 1 表示删除word2第j个字符，所以是前i与j-1的距离+1
- dp[i][j] = dp[i-1][j-1] + 1 表示替换（**因为替换任意一个，所以是+1**）


### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
        if(word2.length() == 0) return word1.length();
        if(word1.length() == 0) return word2.length();
        int[][] dp = new int[word1.length() + 1][word2.length() + 1];
        for (int i = 1; i <= word1.length(); i ++) dp[i][0] = i;
        for (int i = 1; i <= word2.length(); i ++) dp[0][i] = i;
        for (int i = 1; i <= word1.length(); i ++){
            for (int j = 1; j <= word2.length(); j ++){
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
        return dp[word1.length()][word2.length()];
    }
}
```