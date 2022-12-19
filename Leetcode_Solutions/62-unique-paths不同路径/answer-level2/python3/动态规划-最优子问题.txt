    由于机器人先生只能向右或向下走，所以当前位置的路径数是其右侧格子与下侧格子路径数之和，并且最后一行一列每个格子的路径数是1。

    c++代码：
    int uniquePaths(int m, int n) {
        //动态规划，dp为状态表格，(i,j)位置的路径数为其右侧格子的路径数与下方格子路径数之和
        //最右边和最下边的格子路径数都为1，因为只能往下和往右
        int dp[n][m] = {0};
        for(int j = m-1; j >= 0; j--)
        {
            for(int i = n-1; i >= 0; i--)
            {
                if(j == m-1 || i == n-1)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i][j+1] + dp[i+1][j];
            }
        }
        return dp[0][0];
    }

    Python代码：
    def uniquePaths(self, m: int, n: int) -> int:
        #这里将矩阵转置了，左上是终点，右下是起点，方便处理
        dp = [[0 for _ in range(m)] for _ in range(n)]#n行m列
        for j in range(m):
            for i in range(n):
                if i == 0 or j == 0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = dp[i][j-1] + dp[i-1][j]
        return dp[n-1][m-1]

![微信图片_20191018174050.jpg](https://pic.leetcode-cn.com/dac4b14f39ef71cd2d65fbff4fb22d3b79e7479e654c40bc9100b9a1c19d79c7-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191018174050.jpg)
