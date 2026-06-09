Python 的动态规划解法，思想都一样，不过在建立dp数组的时候多出一维，除了dp[0][1]和dp[1][0]初始化为0（因为要保证dp[1][1]等于grid[0][0]），其余都初始化为inf来表示不可从标界到达。这样的话在循环里就可以不考虑标界条件。代码如下：

class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        row = len(grid)
        if not row:
            return None
        col = len(grid[0])
        inf = float('inf')
        dp = [[inf for _ in range(col + 1)] for _ in range(row + 1)]
        #初始化dp，保证dp[1][1] == grid[0][0]
        dp[0][1] = 0
        dp[1][0] = 0
        for i in range(1, row + 1):
            for j in range(1, col + 1):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i -1][j - 1]
        return dp[row][col]