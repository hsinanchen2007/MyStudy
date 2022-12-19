### 解题思路
对动态规划的状态转移方程没有厘清，导致边界条件异常，来回调试六次之后，才终于完成。
* ![dungeon.png](https://pic.leetcode-cn.com/0c21242d9b14b8bb459d65a78f9a8b765b1519d8e04947b63e51c5248daf526e-dungeon.png)

### 代码

```python
class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        从最后的位置往回推导
        dp[i][j] 表示在位置(i,j)最少的生命值
        那么 到达下一个位置 dp[i+1][j] 或者 dp[i][j+1] 的生命值为，dungeon[i][j] + dp[i][j]
        所以逆向推导就得到
        dp[i][j] = dp[i+1][j] - dungeon[i][j]  或者
        dp[i][j] = dp[i][j+1] - dungeon[i][j]
        另外，前提条件是在每个点都是活着，即是 dp[i][j] >= 1
        """
        if not dungeon or not dungeon[0]:
            return 0
        row = len(dungeon)
        col = len(dungeon[0])
        dp = [[1] * col for _ in xrange(row)]
        for i in xrange(row - 1, -1, -1):
            for j in xrange(col - 1, -1, -1):
                if i == (row - 1) and j == (col - 1):
                    if dungeon[i][j] < 1:
                        dp[i][j] = 1 - dungeon[i][j]
                    else:
                        dp[i][j] = 1
                elif i == (row - 1):
                    if dp[i][j+1] - dungeon[i][j] >= 1:
                        dp[i][j] = dp[i][j+1] - dungeon[i][j]
                    else:
                        dp[i][j] = 1
                elif j == (col - 1):
                    if dp[i+1][j] - dungeon[i][j] >= 1:
                        dp[i][j] = dp[i+1][j] - dungeon[i][j]
                    else:
                        dp[i][j] = 1
                else:
                    tmp = min(dp[i][j+1], dp[i+1][j])
                    if tmp - dungeon[i][j] >= 1:
                        dp[i][j] = tmp - dungeon[i][j]
                    else:
                        dp[i][j] = 1
        return dp[0][0]

```