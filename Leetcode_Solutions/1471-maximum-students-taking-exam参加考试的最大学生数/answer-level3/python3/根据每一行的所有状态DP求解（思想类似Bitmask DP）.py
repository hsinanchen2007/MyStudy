每一行的状态都跟上一行的所有状态相关，所以可以列举当前行的所有状态。
例如，当座位有3列时，每一行座位的状态为(0,0,0),(0,0,1),(0,1,0),(0,1,1),(1,0,0),(1,0,1),(1,1,0),(1,1,1)。
由此可以建立dp数组，其中dp[i][j]表示第i行考生状态为j时的前i行最多学生人数，状态转移方程为dp[i][j]=max(dp[i][j],dp[i-1][k]+num).
```python
class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        from itertools import product
        m = len(seats)
        n = len(seats[0])
        row_seat = list(product((0,1), repeat=n)) # 生成每一行所以可能的组合
        for i in range(m):
            for j in range(n):
                seats[i][j] = 1 if seats[i][j] == '.' else 0
        def check_now(row, now): #判断当前行是否为可行状态
            for i in range(n):   # 判断当前状态是否是当前行全集的子集
                if row[i] < now[i]:
                    return False
            for i in range(n-1): # 判断相邻座位是否都为1，如连续相邻座位为1，返回False
                if now[i] + now[i+1] == 2:
                    return False
            return True

        def check_last(last, now): # 判断当前行和上一行是否满足题目要求条件
            for i in range(n):
                if now[i]:
                    if i-1 >= 0 and last[i-1] or i+1 <= n-1 and last[i+1]:
                        return False
            return True
        
        dp = [[-1]*(2**n) for i in range(m+1)]
        dp[0][0] = 0
        for i in range(1, m+1):
            for j, now_seat in enumerate(row_seat):
                if check_now(seats[i-1], now_seat): # 当前座位状态为可能状态
                    for k, last in enumerate(row_seat):
                        if check_last(last, now_seat) and dp[i-1][k] != -1:
                            dp[i][j] = max(dp[i][j], dp[i-1][k] + now_seat.count(1))

        return max(dp[m])
```
