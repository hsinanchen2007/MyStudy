## 解析：
本题为动态规划的基础题。何为动态规划？动态规划讲起来很高大上。说白了就是以空间换时间。类似于缓存。其实就是一个如何去填充缓存数据的问题。
首先。定义一个和原数组一样大的数组dp。dp[m][n]表示（0，0）-->(m,n)的路径的条数。
然后。确定初始值。二维数组一般需要第一行和第一列的值。因为只能向右或者向下。所以从开始到第一行或者第一列都只有一条路径。所以dp[i][0] = 1;dp[0][i] = 1;
然后。因为只能向右或者向下。所以dp[i][j]为从dp[i - 1][j]向右走和从dp[i][j - 1]向下走。即dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
## 代码
```java
public int uniquePaths1(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0;
        }
        if (m == 1 || n == 1) {
            return 1;
        }
        int[][] dp = new int[m][n];

        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

            }
        }
        return dp[m - 1][n - 1];

    }
```
此时时间复杂度和空间复杂度均为O(n^2)。二维的动态规划其实一般可以将空间复杂度转换为一维的。
因为我们在计算没一个位置的时候实际上只和左边的和上边的有关系。

因此。我们其实可以用一维数组来实现这个过程。二维的时候dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
一维的时候dp[j] = dp[j] + dp[j - 1];
```java
//空间压缩
    public int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0;
        }
        if (m == 1 || n == 1) {
            return 1;
        }
        int[] dp = new int[n];
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];

            }
        }
        return dp[n - 1];
    }
```