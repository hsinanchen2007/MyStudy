### 解题思路
因为要找每个1到0的最短距离，比较朴素的想法就是BFS。从0开始遍历相邻的1，然后一层一层往下，每一层的距离在上一层基础上加一。为了防止重复计算和误更新，我们用一个hash set记录访问过的位置。
### 代码

```python
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        if not matrix: return matrix
        m, n = len(matrix), len(matrix[0])
        q = [(i, j) for i in range(m) for j in range(n) if matrix[i][j] == 0]
        s, seen = [], set(q)
        dp = [[0 for _ in range(n)] for _ in range(m)]
        while q:
            while q:
                i, j = q.pop(0)
                for x, y in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
                    if 0 <= x < m and 0 <= y < n and (x, y) not in seen:
                        seen.add((x, y))
                        s.append((x, y))
                        dp[x][y] = dp[i][j] + 1
            q, s = s, q
        return dp
```