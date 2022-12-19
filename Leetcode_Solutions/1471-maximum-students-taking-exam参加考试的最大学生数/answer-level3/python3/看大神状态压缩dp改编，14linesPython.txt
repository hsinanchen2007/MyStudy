1. 首先每行最多8位，因此用位编码表示该行状态，例如：
1 0 0 0 0 1 1 0 表示第1、6、7位上被填充，最差的情况是
0 0 0 0 0 0 0 0 表示没有一位被填充，但是即便是这样，也可以延续状态传递，比起dfs就有了优势，因为dfs有可能会在无法传递的行上断掉。
2. 判断每个状态有效性：由上一步可知，0 0 0 0 0 0 0 0表示没有一个位置被填充，那么他是一个保底的有效状态，另外需要判断有效性的是当前状态有没有出现两个填充连续（左右连续）或者填充的地方在seat当中是否有效。
判断方法是：将状态数向左向右移一位然后与操作，查看是否有数，例如
1 0 0 0 0 *1* **1** 0 原状态
0 1 0 0 0 0 **1** 1 右移
0 0 0 0 1 *1* 0 0 左移
由上可知如果该状态左移、右移后与操作冲突，则该状态不合法，跳过
如果该状态与seat的第i行有状态冲突(与操作即可)，则不合法，跳过
3. 判断延递状态与本行状态关系。
根据2步骤，可以继续判断下一行（顺序）或者上一行（倒叙）与本行的延递关系，方法还是重复上述过程，如果递推的下一行状态ls与本行状态s 有s&ls<<1或者s&ls>>1,表示他们斜相交，不可传递状态，如果判断可以传递状态，则由s代表的dp[i][s]传导到dp[i+1][ls],再加上s对应的1的个数即可。
```
from functools import reduce
class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        m, n = len(seats), len(seats[0]),
        dp = [[0]*(1 << n) for _ in range(m+1)]
        a = [reduce(lambda x,y:x|1<<y,[0]+[j for j in range(n) if seats[i][j]=='#'])  for i in range(m)]
        for row in range(m)[::-1]:
            for s in range(1 << n):
                if not s & s<<1 and not s&s>>1 and not s & a[row]: 
                    for ls in range(1 << n):
                        if not s&ls<<1 and not s&ls>>1:
                            dp[row][s] = max(dp[row][s], dp[row+1][ls] + bin(s).count('1'))
        return max(dp[0])
```

