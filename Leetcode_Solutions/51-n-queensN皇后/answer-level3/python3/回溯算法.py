### 解题思路
此处撰写解题思路
用一维列表(flag)保存前面的信息，其中下标表示行，内容表示列。
### 代码

```python3
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        checkerboard = [['.'] * n for _ in range(n)]
        flag = [0] * n
        res = []

        def DFS(raw, checkerboard, flag):
            if raw == n:
                res.append([''.join(i) for i in checkerboard])
                return

            def canin(raw, j, flag):
                for i in range(raw):
                    if flag[i] == j or abs(raw - i) == abs(flag[i] - j):
                        return False
                return True

            for j in range(n):
                if canin(raw, j, flag):
                    checkerboard[raw][j] = 'Q'
                    flag[raw]=j
                    DFS(raw + 1, checkerboard, flag)
                    checkerboard[raw][j] = '.'
                    flag[raw] = 0
        DFS(0, checkerboard, flag)
        return res
```