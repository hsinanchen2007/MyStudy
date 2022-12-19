[C++代码](https://leetcode-cn.com/problems/minimum-score-triangulation-of-polygon/solution/c-dong-tai-gui-hua-ti-jie-by-da-li-wang-2/)
```java
class Solution {
    public int minScoreTriangulation(int[] A) {
        int length = A.length;
        int[][] dp = new int[length][length];
        for (int[] item : dp)
            Arrays.fill(item, Integer.MAX_VALUE);
        for (int i = 0; i < length; ++i)
            dp[i][(i + 1) % length] = 0; // 两个点构不成三角形，初始化为0

        for (int len = 2; len < length; ++len) {
            for (int i = 0; i < length; ++i) {
                int j = (i + len) % length;
                for (int k = (i + 1) % length; k != j; k = (k + 1) % length)
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j]);
            }
        }
        return dp[0][length - 1];
    }
}
```
