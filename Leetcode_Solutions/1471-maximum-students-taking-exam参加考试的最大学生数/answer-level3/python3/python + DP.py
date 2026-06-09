```python
from functools import lru_cache
class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        # 2 ** 24 =>  1.6 * 107
        row, col = len(seats), len(seats[0])
        def state_ok(s, i): 
            for j in range(col):
                k = s % 2 # k == 1 means empty
                s = s >> 1
                if seats[i][j] == '#' and k == 1: return False
            return True
        @lru_cache(None)
        def conflict(i):
            t = '{:08b}'.format(i)
            for i in range(1, 8):
                if t[i] == '1' and t[i - 1] == '1': return True
            return False
        @lru_cache(None)
        def get_seats(s):
            val, flag = 0, False
            for j in range(col):
                k = s % 2
                if k == 1 and not flag:
                    val += 1
                    flag = True
                else:
                    flag = False
                s = s >> 1
            return val

        flag = [True] * (1 << col)
        ans = 0
        dp = [[0] * (1 << col) for _ in range(row)]
        for i in range(row):
            temp_flag = [False] * (1 << col)
            for j in range(1 << col):
                if state_ok(j, i):
                    temp_flag[j] = True
                    if i == 0: 
                        dp[i][j] = get_seats(j)
                    else:
                        for k in range(1 << col):
                            if flag[k] and not conflict(j|k):
                                dp[i][j] = max(dp[i][j], dp[i - 1][k] + get_seats(j))
                ans = max(ans, dp[i][j])
            flag = temp_flag
        return ans
```