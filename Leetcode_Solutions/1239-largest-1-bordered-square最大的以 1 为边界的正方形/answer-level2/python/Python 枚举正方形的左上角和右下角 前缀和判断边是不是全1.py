![image.png](https://pic.leetcode-cn.com/75a17164ff204c0880b7bc50dea7c7f43f5bb0a257f6ca44c5bde872f0cd401f-image.png)


```
'''
枚举正方形左上角和右下角坐标， 用前缀和思想快速判断
四条边是不是全部为1
'''

from typing import List
class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])

        left_one_cnt = [[0 for _ in range(n)] for _ in range(m)]
        up_one_cnt = [[0 for _ in range(n)] for _ in range(m)]

        for i in range(m):
            left_one_cnt[i][0] = grid[i][0]
            for j in range(1, n):
                left_one_cnt[i][j] = left_one_cnt[i][j-1] + grid[i][j]

        for j in range(n):
            up_one_cnt[0][j] = grid[0][j]
            for i in range(1, m):
                up_one_cnt[i][j] = up_one_cnt[i-1][j] + grid[i][j]

        ans = 0
        for i1 in range(m):
            for j1 in range(n):
                if grid[i1][j1] == 0:
                    continue

                max_len = min( m - i1, n - j1)
                if max_len*max_len <= ans:
                    continue

                for delta in range(max_len-1, -1, -1):
                    i2, j2 = i1 + delta, j1 + delta
                    if i2 >= m or j2 >= n:
                        break

                    if grid[i2][j2] == 0 or grid[i1][j2] == 0 or grid[i2][j1] == 0:
                        continue

                    if left_one_cnt[i1][j2] - left_one_cnt[i1][j1] == j2 - j1 and \
                       left_one_cnt[i2][j2] - left_one_cnt[i2][j1] == j2 - j1 and \
                       up_one_cnt[i2][j1] - up_one_cnt[i1][j1] == i2 - i1 and \
                       up_one_cnt[i2][j2] - up_one_cnt[i1][j2] == i2 - i1:
                        ans = max(ans, (i2 - i1 +1) * (j2 - j1 +1))
                        break

        return ans
```
