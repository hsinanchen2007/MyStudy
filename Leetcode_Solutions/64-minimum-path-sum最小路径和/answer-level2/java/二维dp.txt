### 解题思路
此处撰写解题思路
dp
执行用时 :
4 ms
, 在所有 Java 提交中击败了
37.39%
的用户
内存消耗 :
42.1 MB
, 在所有 Java 提交中击败了
39.94%
的用户
### 代码

```java
class Solution {
    public int minPathSum(int[][] grid) {
        int len1 = grid.length;
        int len2 = grid[0].length;
        int[][] dp = new int[len1][len2];
        for (int i = 0; i < len1; i++){
            for (int j = 0; j < len2; j++){
                if (i == 0 && j == 0) dp[i][j] = grid[i][j];
                else if (i == 0 && j != 0) dp[i][j] = dp[i][j - 1] + grid[i][j];
                else if (i != 0 && j == 0) dp[i][j] = dp[i - 1][j] + grid[i][j];
                else dp[i][j] = Math.min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
        return dp[len1 - 1][len2 - 1];
    }
}
```