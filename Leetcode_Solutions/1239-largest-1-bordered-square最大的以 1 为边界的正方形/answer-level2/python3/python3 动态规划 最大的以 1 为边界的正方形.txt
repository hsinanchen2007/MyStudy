#
# @lc app=leetcode.cn id=1139 lang=python
#
# [1139] 最大的以 1 为边界的正方形
#

# @lc code=start
class Solution(object):
    def largest1BorderedSquare(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        w = len(grid[0])
        h = len(grid)
        import numpy as np 
        dp = np.zeros((h+1,w+1,2), dtype=np.int32)
        # dp = [[[0]*2]*(w+1) for _ in range(h+1)]
        for i in range(1,h+1):
            for j in range(1,w+1):
                if grid[i-1][j-1] == 0:
                    continue
                dp[i][j][0] = dp[i-1][j][0] + 1  # 0 代表 上边
                dp[i][j][1] = dp[i][j-1][1] + 1  # 1 代表 左边
        max_grid = 0
        for i in range(1,h+1):
            for j in range(1,w+1):
                if grid[i-1][j-1] == 0:
                    continue 
                k = min(dp[i][j][0], dp[i][j][1])  # 取出可能的最大的边长
                while k >=0:
                    if dp[i-k+1][j][1] >=k and dp[i][j-k+1][0] >=k:  #注意1： 注意位置与长度的变换，长度为1的时候 ，k是长度，现在我们要换算成坐标的话要+1，很容易想到 自身就是长度为1的
                        max_grid = max(max_grid, k*k)
                        break 
                    k -= 1
        return max_grid

        
# @lc code=end

if __name__ == '__main__':
    a  = Solution()
    a  = a.largest1BorderedSquare([[1,1,1],[1,0,1],[1,1,1]])
    print(a)