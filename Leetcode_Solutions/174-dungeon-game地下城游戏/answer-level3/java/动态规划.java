### 解题思路
此题为64题的加强版。但这一题需要逆过来想，从下往上初始化。
此时dp[i][j]的含义为：至少的血量，并且这个血量必须大于1。如果你到这的时候已经是1，那么至少就选1，如果你到这的血量小于1，那么此时的血量必须为1，。
然后当地牢为一格的时候，dp = max(1, 1 - dungeon[0][0]); dungeon为正的时候dp取1，dungeon为负的时候，dp = 1 - dungeon;
然后初始化最右侧和最下侧的地牢。
然后就可以初始化其他层次。
dp[i][j] = Math.max(1, Math.min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);

### 代码

```java
class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        
        int m = dungeon.length;
        int n = dungeon[0].length;
        
        int[][] dp = new int[m][n];
        dp[m-1][n-1] = Math.max(1, 1 - dungeon[m-1][n-1]);
        for(int i = m - 2; i >= 0; i--){
            dp[i][n-1] = Math.max(1, dp[i+1][n-1] - dungeon[i][n-1]);
        }
        for(int i = n - 2; i >= 0; i--){
            dp[m-1][i] = Math.max(1, dp[m-1][i+1] - dungeon[m-1][i]);
        }

        for(int i = m - 2; i >= 0; i--){
            for(int j = n - 2; j >= 0; j--){
                int dpmin = Math.min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = Math.max(1, dpmin - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
}
```