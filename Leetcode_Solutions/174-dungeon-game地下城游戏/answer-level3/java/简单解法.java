    
动态规划
一开始的思路以为直接求最大路径就行了，但是假如有一条路径和最大，并且第一个格子是1
但是你要走的第二个格子就是-100，那么你就需要初始值是101
而另一条路径和虽然是0，但是走的路径是1，-1，1，-1，说明初始值是2就ok了，显然这个思路不成立
所以需要从右下角向左上角推
规则就是，需要消耗的魔法值(肯定选择最小的) - 自己已有的魔法值
dp[i][j] = Math.min(dp[i + 1][j],dp[i][j + 1]) - m[i][j]
所以从下往上推，从右往左推
dp[j]代表的就是来到这个格子你需要有多少魔法值
执行用时 :2 ms, 在所有 Java 提交中击败了99.77%的用户
```
class Solution {
    public int calculateMinimumHP(int[][] m) {
        int M = m.length;
        int N = m[0].length;
        int[] dp = new int[N];
        dp[N - 1] = m[M - 1][N - 1] >= 0 ? 1 : 1 - m[M - 1][N  - 1];
        for(int i = N - 2; i >= 0; i--) {
            dp[i] = dp[i + 1] - m[M - 1][i];
            if(dp[i] <= 0) {
                dp[i] = 1;
            }
        }
        
        for(int i = M - 2; i >= 0; i--) {
            
            for(int j = N - 1; j >= 0; j--) {
                if(j == N - 1) {
                    dp[j] = dp[j] - m[i][j];
                }else {
                    dp[j] = Math.min(dp[j],dp[j + 1]) - m[i][j];
                }
                if(dp[j] <= 0) {
                    dp[j] = 1;
                }
            }
            
        }
        return dp[0];
        
        
    }
}
```
