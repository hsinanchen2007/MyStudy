    首先考虑用dp[i][j]来保存到(i,j)坐标下的不同路径数，因为是动态规划，所以自底向上那么就先找底，底肯定是dp[0][0] = 1；显而易见到(0,0)位置的路径数就是1；
    接下来考虑递推式，如何通过dp[0][0]找到dp[n-1][m-1]呢？
![image.png](https://pic.leetcode-cn.com/7c0e90588999b65f82d15ac2bdeffd390f052581e4d12b76e7a075ff21127086-image.png)
    如下图所示，对于每一个dp[i][j]我们可以求出他dp[i+1][j]和dp[i][j+1],那么我们通过求出第一行所有的dp[0][j]就可以不仅获取到第一行所有的信息，同时可以求出第二行所有的信息了，因为每一个位置还可以确定它下面的值。这时候就发现不需要二维数组了，因为他只需要它上一行和它同一列的dp值和他左边的dp值，它们相加就是要确定位置的dp值了。
```
public class UniquePaths62 {
    public int uniquePaths(int m, int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        for(int i=0;i<m;i++)//这样可以算每一行
        {
            for(int j=1;j<n;j++)
            {
                dp[j] = dp[j]+dp[j-1];
            }
        }
        return dp[n-1];
    }
}
```
这样不需要使用二维数组，可以节省空间