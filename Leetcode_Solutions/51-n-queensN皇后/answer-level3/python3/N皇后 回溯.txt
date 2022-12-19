回溯的答题框架：

result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择

此题的答题思路：
从第一行开始找起，要是有符合条件的(row,col)，则将在此处放入皇后，进入下一行继续查找，要是某一行没有找到说明上一步有问题，则向上回溯，即将上一步放入的皇后去掉

皇后的攻击范围：同行，同列，主对角线（行数-列数=常数），辅对角线（行数+列数=常数） 
def backtrack(路径, 选择列表):
    if 满足结束条件:<==> row==len(board)(即找到最后一行了)
        result.add(路径)
        return

    for 选择 in 选择列表:（选择列表为每一行的元素）
        做选择   if 满足不被其他皇后攻击的条件：
                     将board中此处改为'Q'
        backtrack(路径, 选择列表)
        撤销选择     将board中此处改为'.'
                 else:
                    continue

代码如下
```
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def isvalid(board,row,col):
            n=len(board)
            for i in range(n):
                if board[i][col]=='Q' or board[row][i]=='Q':
                    return False
            for i in range(n):
                for j in range(n):
                    if (board[i][j]=='Q' and (i+j==row+col or i-j==row-col)):
                        return False
            return True
        def backtrack(board,row):
            if row==len(board):
                res1=[]
                for i in board:
                    add_yinhao="".join(i)
                    res1.append(add_yinhao)
                res.append(res1)
                return
            for col in range(len(board)):
                if isvalid(board,row,col):
                    board[row][col]='Q'
                    backtrack(board,row+1)
                    board[row][col]='.'
                else:
                    continue
        board = [['.']*n for i in range(n)]
        res=[]
        backtrack(board,0)
        return res
```
题目N皇后2中 返回len(res)即可