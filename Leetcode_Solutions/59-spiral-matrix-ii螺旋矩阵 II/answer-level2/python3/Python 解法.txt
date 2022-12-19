### 解题思路
这道是56题螺旋矩阵的延伸，思路一样，分析和更多解法参考：
https://leetcode-cn.com/problems/spiral-matrix/solution/python-san-chong-jie-fa-by-hialiens/

### 代码

```python3
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if n == 0: return []
        # if n == 1: return 1

        row = col = n
        ans = [[False] * row for _ in range(col)]
        dr = [0, 1, 0, -1]
        dc = [1, 0, -1, 0]
        r = c = di = 0

        for v in range(1, row * col + 1):
            ans[r][c] = v
            cr, cc = r + dr[di], c + dc[di]
            if 0 <= cr < row and 0 <= cc < col and not ans[cr][cc]:
                r = cr
                c = cc
            else:
                di = (di + 1) % 4
                r, c = r + dr[di], c + dc[di]
        
        return ans

```