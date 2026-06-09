### 解题思路

图的遍历，广搜或者深搜


### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        
        def check(i, j):
            tmp = 0
            while i:
                tmp += ( i % 10)
                i = i // 10
            while j:
                tmp += (j % 10)
                j = j // 10
            return tmp <= k
        
        def ok(i, j):
            return i >= 0 and i < m and j >= 0 and j < n and not vis[i][j] and check(i, j) 
        
        vis = [[False] * n for _ in range(m)]
        vis[0][0] = True
        res = 1
        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        s = [[0, 0]]
        while len(s):
            t = []
            for x in s:
                for _dir in dirs:
                    x_ = x[0] + _dir[0]
                    y_ = x[1] + _dir[1]
                    if ok(x_, y_):
                        res += 1
                        vis[x_][y_] = True
                        t.append([x_, y_])
            s = t
        return res
```