找最低解的方式一般都是用二分查找的方式，把r设成2000想优化下时间赌了下case,结果还是很慢，实际可以循环把负数加起来，不过我这个算法是n^2logn的复杂度有点高，后续想看看其他人怎么写的，主要技巧还是二分技巧，找解决方案一般有两种方式贪心或动规，贪心想不到，我用的动规，动规每一步到达某个格子处所有合法路径的最高体力，如果在终点体力值大于0，那么可以往上找，否则往下找，注意边界不能为0所以初始时l设为1
```
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        if len(dungeon) == 1 and len(dungeon[0]) == 1:
            if dungeon[0][0] > 0:
                return 1
            else:
                return 1- dungeon[0][0]
        l = 1
        r = 2000
        m = len(dungeon)
        n = len(dungeon[0])
        while l < r:
            mid = l + r >> 1
            dp = [[-0x3f for _ in range(n)] for _ in range(m)]
            dp[0][0] = mid + dungeon[0][0]
            for i in range(m):
                for j in range(n):
                    if i > 0 and dp[i-1][j] > 0:
                        dp[i][j] = max(dp[i][j],dp[i-1][j] + dungeon[i][j])
                    if j > 0 and dp[i][j-1] > 0:
                        dp[i][j] = max(dp[i][j],dp[i][j-1] + dungeon[i][j])

            if dp[m-1][n-1] > 0:
                r = mid
            else:
                l = mid + 1 
        return l
```
