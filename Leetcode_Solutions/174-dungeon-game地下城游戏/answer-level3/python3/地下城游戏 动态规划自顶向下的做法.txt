这个题目的最优解法其实是自底向上的动态规划.
但是我发现没有自顶向下的题解,所以想在这里写一下自顶向下的做法.
当我们用自顶向下去解决这个问题的时候，我们会发现这样一个问题.
假设到达(i,j)位置上方(i-1,j)记录的需要的最小hp是3,而当前累计的hp值是20;而到达(i,j)位置左边的(i,j-1)记录的需要的最小hp是5,但是当前累计的hp值是30.
如果这时候我们只考虑需要最小hp的路径也就是说选择(i,j)上方(i-1,j)的状态，作为该位置的最优子状态.
假设在(i,j)位置的右侧(i+1,j),其格子内的数字是(-30),此时更新我们的状态,我们会发现由于当前累计的hp为负值,且绝对值大于3,所以到达这个位置的最小hp更新为10.
但是如果我们之前选择的是(i,j-1)这个位置传递过来的状态呢？我们会发现当前的累计hp为0,但是由于其绝对值要小于5,所以到达这个位置的最小hp不更新,仍然是5。

所以,即使是(i,j)这个位置的最优解,不一定能作为(i+1,j)这个位置的最优子状态.
因此,我们需要在这个位置将两个状态都保留下来.
但是另外一个问题又出现了,如果用这样的做法，那就有太多需要保留的状态了.

所以,我们要进行状态之间的比较:
如果状态1的当前累计hp a1 >= 状态2的当前累计hp a2,并且状态1的记录的最小hp值 b1 <= 状态2的记录的最小hp值,那么我们就可以将状态2淘汰了,因为无论下一个位置的数字是什么,状态1都是优于状态2的状态.

这样的比较能够大大的减少我们需要保留的状态,到这里我们就完成了自顶向下的动态规划.
```py
import copy
class Solution:
    def calculateMinimumHP(self, dungeon: list) -> int:
        row,column = len(dungeon),len(dungeon[0])
        dp = [[[] for _ in range(column)] for _ in range(row)]
        dp[0][0].append([dungeon[0][0],min(0,dungeon[0][0])])
        for i in range(1,row):
            dp[i][0].append([dungeon[i][0] + dp[i-1][0][0][0],min(dp[i-1][0][0][1],dungeon[i][0] + dp[i-1][0][0][0])])
        for j in range(1,column):
            dp[0][j].append([dungeon[0][j] + dp[0][j - 1][0][0], min(dungeon[0][j] + dp[0][j-1][0][0],dp[0][j-1][0][1])])
        for i in range(1,row):
            for j in range(1,column):
                # 保留状态
                dp[i][j] = copy.deepcopy(dp[i-1][j] + dp[i][j-1])
                # 对保留下来的状态加上当前的格子的数字
                for k in range(len(dp[i][j])):
                    dp[i][j][k] = [dp[i][j][k][0] + dungeon[i][j],min(dp[i][j][k][0] + dungeon[i][j],dp[i][j][k][1])]
                # 以当前的hp为key,对状态进行排序
                dp[i][j] = sorted(dp[i][j],key=lambda x:-x[0])
                # 对部分状态进行淘汰
                self.Eliminate(dp, i, j)
        return abs(sorted(dp[-1][-1],key=lambda x:-x[1])[0][1]-1)
    @staticmethod
    def Eliminate(dp, i, j):
        index = 0
        while index < len(dp[i][j]):
            min_need_hp = dp[i][j][index][1]
            compare = index + 1
            while compare < len(dp[i][j]):
                if min_need_hp >= dp[i][j][compare][1]:
                    dp[i][j].pop(compare)
                else:
                    break
            index = index + 1
```

当然,效率就特别感人了...
