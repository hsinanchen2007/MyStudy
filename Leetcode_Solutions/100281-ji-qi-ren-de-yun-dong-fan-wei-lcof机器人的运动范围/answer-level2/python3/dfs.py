### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        if (m == 0 or n == 0): return 0
        self.ans = 0
        flg = [[False] * n for _ in range(m)]

        def dfs(x, y):
            x1, x2 = x // 10, x % 10
            y1, y2 = y // 10, y % 10
            if x1 + x2 + y1 + y2 > k: return
            self.ans += 1
            xx = x - 1
            yy = y
            if xx >= 0:
                if not flg[xx][yy]:
                    flg[xx][yy] = True
                    dfs(xx, yy)

            xx = x + 1
            yy = y
            if xx < m:
                if not flg[xx][yy]:
                    flg[xx][yy] = True
                    dfs(xx, yy)
            xx = x
            yy = y - 1
            if yy >= 0:
                if not flg[xx][yy]:
                    flg[xx][yy] = True
                    dfs(xx, yy)
            xx = x
            yy = y + 1
            if yy < n:
                if not flg[xx][yy]:
                    flg[xx][yy] = True
                    dfs(xx, yy)
        flg[0][0] = True
        dfs(0, 0)
        return self.ans
```