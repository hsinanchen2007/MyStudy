    def minPathSum(self, grid: List[List[int]]) -> int:
        """
        #64 最小路径和 动态规划
        两种策略：
        1、构建一个和grid同样大小dp，dp[i][j]表示到i，j位置所需要的最小路径，动态方程：
                    dpi][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1])，考虑到每次计算dp[i][j]时都只用到grid[i][j],可以直接把grid当dp用
        2、仔细想这个计算过程，其实每一个dp[i][j]都只用到同一行前一列和同一列前一行的dp值，故可以构建一个长度为n的数组，每循环一行更新到达每一列所需最短路径，即更新一遍dp值，当循环下一行时
            此时这一行每一列可以由上一行对应列上和当前行前一列最小值获得，而此时前一列已经更新了，dp也可以dp=grid[0]直接初始化
        两种策略都要注意下边界情况，第二种其实也可以列循环套行，此时dp长度应该为m用来保存到达每一列时对应的最小路径，复杂度均为O(mn),空间复杂度由于修改gird都可以降至O(1)
        至于从头开始还是从尾开始，肯定都可以的，因为两个点肯定都是要经过的，从头到尾和从尾到头最短路径肯定是相同的
        :param grid:
        :return:
        """
        m = len(grid)
        if not m:
            return 0
        n = len(grid[0])
        if not n:
            return 0

        # ######## 策略2 ##########
        # dp = grid[0]
        # for i in range(m):
        #     for j in range(n):
        #         if i == j == 0:
        #             continue
        #         if j and i:
        #             dp[j] = grid[i][j] + min(dp[j], dp[j - 1])
        #         elif j:
        #             dp[j] = grid[i][j] + dp[j - 1]
        #         else:
        #             dp[j] = grid[i][j] + dp[j]
        #######################################

        # #######策略1########
        dp = grid
        for i in range(m):
            for j in range(n):
                if i == j == 0:
                    continue
                if j and i:
                    dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
                elif j:
                    dp[i][j] = grid[i][j] + dp[i][j-1]
                elif i:
                    dp[i][j] = grid[i][j] + dp[i-1][j]

        return dp[m-1][n-1]