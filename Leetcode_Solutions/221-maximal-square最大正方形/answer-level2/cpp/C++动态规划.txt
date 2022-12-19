C++，动态规划。

这里使用二维数组dp，然后 `dp[i][j]`记录以该元素为右下角的最大正方形的边长，于是就有了转换公式：

$$
dp[i][j]=\left\{
\begin{aligned}
min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1 & & matrax[i][j] = 1 \\
0 & & matrax[i][j] = 0 \\
\end{aligned}
\right.
$$

然后取最大的`dp[i][j]`作为答案就好了。。。

当然最大的疑问就是上面哪个公式是怎么来的。。。

画个图会好一点估计，但我懒得画了，其实想象一下那个图就可以了。

![](https://pic.leetcode-cn.com/5eb97f458fa22b16f2ceda106dc908079ec60f96aa28786b2c24e585c9c609d5-file_1574354773852)

对，大概就是这样的，图是自己瞎画的2333。

代码如下：

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int ans = 0;
        if (m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    if (i > 0 && j > 0) {
                        if (dp[i-1][j-1] > 0 && dp[i-1][j] && dp[i][j-1]) {
                            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                        }
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans * ans;
    }
};
```