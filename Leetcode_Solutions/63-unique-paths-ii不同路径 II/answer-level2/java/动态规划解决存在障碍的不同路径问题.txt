### 解题思路
相对于62题，这道题的不同点，在于初始值不同，且在递推关系时，如果有障碍物，则该节点的值为0。
在dp[i][0]和dp[0][j]，即最左侧一列和最上边一行，如果前边有一个障碍物，则后续的值均为0。
代码如下：

### 代码

```java
/**
 * Description：
 * 63. 不同路径 II
 * https://leetcode-cn.com/problems/unique-paths-ii/
 *
 * @author YoungBear
 * @since 2019/12/11 19:42
 */
public class Solution {
    public static void main(String[] args) {
        Solution test = new Solution();
        int[][] obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
        System.out.println(test.uniquePathsWithObstacles(obstacleGrid));
    }

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        if (m <= 0) {
            return 0;
        }
        int n = obstacleGrid[0].length;
        if (n <= 0) {
            return 0;
        }
        int[][] dp = new int[m][n];
        boolean iBlock = false;
        for (int i = 0; i < m; i++) {
            if (iBlock) {
                dp[i][0] = 0;
            } else {
                if (obstacleGrid[i][0] == 1) {
                    iBlock = true;
                    dp[i][0] = 0;
                } else {
                    dp[i][0] = 1;
                }
            }
        }
        boolean jBlock = false;
        for (int j = 0; j < n; j++) {
            if (jBlock) {
                dp[0][j] = 0;
            } else {
                if (obstacleGrid[0][j] == 1) {
                    jBlock = true;
                    dp[0][j] = 0;
                } else {
                    dp[0][j] = 1;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                // 递推关系
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
}

```