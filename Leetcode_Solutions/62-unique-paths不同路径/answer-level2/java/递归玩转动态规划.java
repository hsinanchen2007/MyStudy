这题非常明确的提供了一张二维数组，非常容易联想到动态规划，那么关键就是理解它的递推逻辑。

- 问题非常简单，小人只可以向下或者向右走，那么分别计算出向下和向右的路径和就可以求出最终的路径总数。
- 下图提供分析思路：
![不同路径思路分析](https://pic.leetcode-cn.com/540abe09c89df4cb35bd76a0380c40f7f8d90e60d6b953e51ae6cc5897394bcf.png)
- 根据上图的逻辑，暴力递归
```
    public static int uniquePaths(int m, int n) {
        return getRes(0, 0, m, n);   // 从0，0位置出发
    }

    private static int getRes(int r, int c, int m, int n) {
        if (r == m - 1 || c == n - 1) return 1;
        return getRes(r + 1, c, m, n) + getRes(r, c + 1, m, n);  // 下边和加上右边和
    }
```
- 感受一下暴力递归的华丽之处，代码非常简短，可惜超时
- 非常明确的知道，当前的格子依赖它右边和下面的格子，构建动态规划。
```
    public static int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 || j == n - 1) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }
        return dp[0][0];
    }
```
- 完全依赖递归的思路修改，这里因为我们没求一个结果的时候，都只用到了下面的格子和右边的格子，所以完全可以降低dp数组的维度，只用一个一维数组不断更新就可以实现了。
```
    public static int uniquePaths(int m, int n) {
        int[] dp = new int[n];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 || j == n - 1) {
                    dp[j] = 1;
                } else {
                    dp[j] = dp[j] + dp[j + 1];
                }
            }
        }
        return dp[0];
    }
```
- 直接将dp的中有关i的位置全部干掉就可以了。