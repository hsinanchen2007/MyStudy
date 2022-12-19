### 解题思路
此处撰写解题思路
注意边界处理，也可以加边
最简单的二维dp了吧
执行用时 :
4 ms
, 在所有 Java 提交中击败了
34.77%
的用户
内存消耗 :
42.1 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    public int maxValue(int[][] grid) {
        int len1 = grid.length;
        int len2 =  grid[0].length;
        int[][] dp = new int[len1][len2];
        dp[0][0] = grid[0][0];
        for (int i = 0; i < len1; i++){
            for (int j = 0; j < len2; j++){
                if (i == 0 && j == 0) continue;
                else if (i == 0) dp[i][j] = dp[i][j-1] + grid[i][j];
                else if (j == 0) dp[i][j] = dp[i-1][j] + grid[i][j];
                else dp[i][j] = Math.max(dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j]);
            }
        }
        return dp[len1-1][len2-1];
    }
}
```