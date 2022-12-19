### 动态规划思路
dp[i][j]表示以A中第i行第j列位置为结束点时，对应的下降路劲最小和：

dp[i][j] = min{dp[i-1][j], dp[i-1][j+1]} + A[i][j], j = 0(前面第一列) 

dp[i][j] = min{dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]} + A[i][j], 1 < j < A.length-1 (中间列)

dp[i][j] = min{dp[i-1][j-1], dp[i-1][j]} + A[i][j], j = A.length-1(最后一列) 

返回dp中最后一行中最小值，即为下降路劲最小和。时间复杂度O(n^2)，空间复杂度O(n^2)

### 代码实现
```java
class Solution {
    public int minFallingPathSum(int[][] A) {
        int len = A.length;
        int[][] dp = new int[len][len];
        for(int i = 0; i < len; i++){
            dp[0][i] = A[0][i];
        }
        for(int i = 1; i < len; i++){
            // 第一列计算
            dp[i][0] = Math.min(dp[i-1][0], dp[i-1][1]) + A[i][0];
            // 中间列计算
            for(int j = 1; j < len-1; j++){
                dp[i][j] = Math.min(Math.min(dp[i-1][j-1], dp[i-1][j]), dp[i-1][j+1]) + A[i][j];
            }
            // 最后一列计算
            dp[i][len-1] = Math.min(dp[i-1][len-2], dp[i-1][len-1]) + A[i][len-1];
        }
        int res = Integer.MAX_VALUE;
        // 求最后一行中的最小值
        for(int j = 0; j < len; j++){
            res = Math.min(res, dp[len-1][j]);
        }
        return res;
    }
}
```

### 动态规划改进
其实这个问题存储子问题的解，不需要全部存和A一样大的空间结果，从状态方程可以发现，每次新的结果只是与前面一行的结果相关。所以我们可以直接用两行来存储结果，dp[2][A.length]的空间已经可以了，每次用一行存储之前的结果，另一行存新的结果。

这样时间复杂度还是O(n^2)，但是空间复杂度降到O(n)。

```java
class Solution {
    public int minFallingPathSum(int[][] A){
        int len = A.length;
        int[][] dp = new int[2][len];
        for(int i = 0; i < len; i++){
            dp[0][i] = A[0][i];
        }
        for(int i = 1; i < len; i++){
            int k = i % 2; // k = 0 or 1
            // 第一列结果
            dp[k][0] = Math.min(dp[1-k][0], dp[1-k][1]) + A[i][0];
            // 中间列结果
            for(int j = 1; j < len-1; j++){
                dp[k][j] = Math.min(Math.min(dp[1-k][j-1], dp[1-k][j]), dp[1-k][j+1]) + A[i][j];
            }
            // 最后一列结果
            dp[k][len-1] = Math.min(dp[1-k][len-2], dp[1-k][len-1]) + A[i][len-1];
        }
        int res = Integer.MAX_VALUE;
        int k = (len-1) % 2; // 需要判断最终的结果存在dp中第一行，还是第二行
        for(int j = 0; j < len; j++){
            res = Math.min(res, dp[k][j]);
        }
        return res;
    }
}
```