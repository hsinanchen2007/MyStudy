### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        boardused = [False] * n        #行、列是否被攻击到
        diagused = [False] * (2*n-1)   #主对角线是否被攻击到
        subdiagused = [False] * (2*n-1)   #副对角线是否被攻击到
        board = [['.'] * n for i in range(n)]    #建棋盘
        res = []   #返回值
        def backtrack(board, r, n):      #开始回溯算法
            if r >= n:      #当每一行中，所有列都遍历完成后
                res.append(["".join(i) for i in board])    #把棋盘中的值放入返回值中
                return    #退出
            for i in range(n):   #对每一行的列进行遍历
                if not (boardused[i] or diagused[r - i + n - 1] or subdiagused[r + i]):  #如果不会被攻击到
                    board[r][i] = 'Q'    #放皇后
                    boardused[i] = True   #架炮台，对准行和列
                    diagused[r - i + n - 1] = True  #架炮台，对准主对角线 
                    subdiagused[r + i] = True   #架炮台，对准副对角线
                    backtrack(board, r+1, n)   #回溯下一行
                    board[r][i] = '.'   #如果下一行被攻击到了
                    boardused[i] = False   #撤炮台，重新寻找合适的位置
                    diagused[r - i + n - 1] = False  #撤炮台，重新寻找合适的位置
                    subdiagused[r + i] = False  #撤炮台，重新寻找合适的位置
        backtrack(board, 0, n)
        return res
           
```