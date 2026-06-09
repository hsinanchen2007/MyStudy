### 解题思路
* 自底向上动态规划高级算法，需要多琢磨一段时间
* 参考其他人的实现方法
* 算法说明：
 动态规划一般由两种方法来实现：
一种为自顶向下的备忘录方式，用递归实现，
一种为自底向上的方式，用迭代实现。


### 代码

```java
class Solution {
     
     public int cherryPickup(int[][] grid) {    
        // 自底向上动态规划算法
        int N = grid.length;
        int[][] dp = new int[N][N];
        for (int[] row: dp) {
            Arrays.fill(row, Integer.MIN_VALUE);
        }
        dp[0][0] = grid[0][0];

        for (int t = 1; t <= 2*N - 2; ++t) {
            int[][] dp2 = new int[N][N];
            for (int[] row: dp2) {
                Arrays.fill(row, Integer.MIN_VALUE);
            }

            for (int i = Math.max(0, t-(N-1)); i <= Math.min(N-1, t); ++i) {
                for (int j = Math.max(0, t-(N-1)); j <= Math.min(N-1, t); ++j) {
                    if (grid[i][t-i] == -1 || grid[j][t-j] == -1) {
                        continue;
                    }
                    int val = grid[i][t-i];
                    if (i != j) {
                        val += grid[j][t-j];
                    }
                    for (int pi = i-1; pi <= i; ++pi) {
                        for (int pj = j-1; pj <= j; ++pj) {
                            if (pi >= 0 && pj >= 0) {
                                dp2[i][j] = Math.max(dp2[i][j], dp[pi][pj] + val);
                            }
                        }
                    }
                }
            }
            dp = dp2;
        }
        return Math.max(0, dp[N-1][N-1]);
    }
}
```