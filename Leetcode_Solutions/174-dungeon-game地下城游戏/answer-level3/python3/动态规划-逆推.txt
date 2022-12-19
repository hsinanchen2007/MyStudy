### 解题思路
## dp[i][j] 表示到(i,j)的所需最小的能量值。
但是需要注意的是并不能从左上角递推到右下角，因为当前的状态的抉择要受到后面状态的影响，
这不适用动态规划无后效性的要求。只能从右下角递推到左上角。
## 先来说明递推式子:
    1. 首先初始化最后一行
        当前状态要由前面状态所需最小能量值减去当前需消耗(或增加)的能量值，且当前状态         所需的能量值最小为1。
        dp[-1][i] = max(1,dp[-1][i+1] - dungeon[-1][i])
    
    2. 初始化最后一列
       同初始化最后一行。
       dp[i][-1] = max(1,dp[i+1][-1] - dungeon[i][-1])
    3. 递推状态
       当前状态dp(i,j)由dp(i+1,j)和dp(i,j+1)两个状态决定，即从两个状态选取最小。
       dp[i][j] = max(1,min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j])
    说明
        现在来解释一下为什么不能从前往后面推：
        若dungeon等于如下矩阵:
        [
            -2 -3 3
            -18 -20 -1
            -1 50 2
        ]
        那么由从前往后面推,得dp矩阵:
        [
            -2 -5 -2
            -20 -23 -3
            -21 29 31
        ]
        这样得到dp[-1][-1]值为最大，且该路径为(1,1)->(2,1)->(3,1)->(3,2)->(3,3)，
        但是需要初始能量值为22，而该情况最小能量值只需"4"即可。究其原因，需尽可能
        保证当前所需能量最小，也要保证整条路径所需能量最小，即需要考虑到两个因素。

### 代码

```python3
class Solution:
    def calculateMinimumHP(self, dungeon):
        '''
        dp[i][j] 表示从(0,0)出发到(i,j)的最小值
        递推式子:
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + dungeon[i][j]
        '''
        if dungeon == [[]]:
            return 0
        M,N = len(dungeon),len(dungeon[0])
        dp = [[0 for _ in range(N+1)] for _ in range(M+1)]
        
        dp[M][N] = max(1,1-dungeon[M-1][N-1])
        #最后一行
        for i in range(N-1,0,-1):
              dp[-1][i] = max(1,dp[-1][i+1]-dungeon[-1][i-1])
        #最后一列
        for i in range(M-1,0,-1):
              dp[i][-1] = max(1,dp[i+1][-1]-dungeon[i-1][-1])
        for i in range(M-1,0,-1):
              for j in range(N-1,0,-1):
                  dp[i][j] = max(1,min(dp[i+1][j],dp[i][j+1])-dungeon[i-1][j-1])
#         for i in dp:
#             print(i)
        return dp[1][1]
```