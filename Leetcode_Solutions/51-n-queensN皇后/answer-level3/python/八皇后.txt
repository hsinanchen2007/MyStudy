### 解题思路
经典回溯
注意python里str是不能进行修改的, 要先存成list[list[char]]再用join进行一些转换
每次逐层向下遍历, 在每层去遍历每列的情况. 因为是逐层向下, 所以判断合法的时候只需要判断当前row上面的皇后摆放情况就可以了, 因为下面的棋盘是空的

### 代码

```python3
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def isvalid(b, r, c):
            # 只需要遍历row以上列, 因为该行一定只有当前一个Q
            for i in range(r):
                if b[i][c]=='Q': return False
            i = j = 0            
            # 只用遍历左上和右上, 因为row下面还没填
            while i<=c and j<=r: # 左上
                if b[r-j][c-i]=='Q': return False
                i, j = i+1, j+1
            i = j = 0
            while r-j>=0 and c+i<n: # 右上
                if b[r-j][c+i]=='Q': return False
                i, j = i+1, j+1
            return True            
        def backtrap(b, row):
            nonlocal res
            if row==n: 
                res.append([''.join(b[x]) for x in range(n)])
                return 
            for col in range(n):
                if not isvalid(b, row, col): continue
                b[row][col] = 'Q'
                backtrap(b, row+1)
                b[row][col] = '.'
        res = []        
        board = [['.']*n for _ in range(n)]
        backtrap(board, 0)
        return res

```