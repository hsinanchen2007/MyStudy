### 解题思路
深度优先遍历（递归）
ps: 也可以用广度优先遍历（队列）

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def calNums(x, y):
            tmp = list(str(x) + str(y))
            return sum(map(int, tmp))

        def isValid(x, y):
            return x>=0 and x<m and y>=0 and y<n

        def dfs(x, y, k):
            # 递归出口：如果坐标越界 或 坐标位数和大于k 或 该坐标已经访问过，则不再向下遍历
            if not isValid(x, y) or calNums(x, y) > k or flags[x][y]==1:
                return
            # 若未从递归出口返回，说明该坐标位置符合要求，flag置1
            flags[x][y] = 1
            # 再向各方向递归遍历
            for d in directions:
                dfs(x+d[0], y+d[1], k)

        flags = [[0 for _ in range(n)] for _ in range(m)]
        directions = [(0, 1), (1, 0)] # 该题由于是从(0,0)开始，所以只需要遍历右和下的方向
        dfs(0, 0, k)
        # 计算flags中1的数量，即为结果
        res = 0
        for i in range(m):
            for j in range(n):
                if flags[i][j] == 1:
                    res += 1
        return res
            



```