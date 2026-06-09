### 思路
按照题目意思, 可以知道当前行的状态之和前一行的状态有关, 而每一行的状态最多有`2^8 = 256`, 每一行只有8个座位.
$$
dp[i][j] = max_{j \in [1, 256]}(dp[i-1][j] + count(j)) 
$$
`count(j)`表示: `j`的二进制表示, 的`1`的数量.
### 位操作
将`seats`每一行转换为二进制表示, `'#'=0, '.'=1`, 每一行记为`row[i]`
状态同样是使用二进制表示, `1`:表示有人做, `0`:表示没有人做, 设当前状态码为`j`, 之前一行的状态码为`k`.
首先做人的座位, 左右两边都不能做人的充要条件为: `j & (j << 1) == 0 and j & (j >> 1) == 0`
人不能坐在坏的座位上的充要条件为: `j & row[i] == j`
人做的位置,前面一行左右位置不能做人的充要条件为: `j & (pre << 1) == 0 and j & (pre >> 1) == 0`


```
class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        dp = {0:0} # 第一行的前一行, 可以假设有第0行, 且没有任何人做
        arr = [0] * len(seats)
        for i, row in enumerate(seats): # 将座位状态转换为二进制表示
            for j in row:
                arr[i] = arr[i] * 2 + (1 if j == '.' else 0)
        for i in range(len(arr)): # 按行进行动态规划
            newdp = {}
            for j in range(1 << len(seats[0])):
                if j & arr[i] != j or j & (j << 1) != 0 or j & (j >> 1) != 0: continue 
                #  j & arr[i] != j : 表示有人坐在坏的座位上
                #  j & (j << 1) != 0 or j & (j >> 1) != 0: 表示存在有人坐在一起的情况
                num = bin(j).count('1')
                for k, v in dp.items():
                    if j & (k << 1) != 0 or j & (k >> 1) != 0: continue #存在前面一排, 有位置的左右两边有人做
                    newdp[j] = max(newdp.get(j, 0), v + num)
            dp = newdp
        return max(dp.values())
```
