执行用时 :156 ms, 在所有 Python3 提交中击败了90.97%的用户
内存消耗 :13.8 MB, 在所有 Python3 提交中击败了5.22%的用户




 
    解题思路：        
        我们定义dfs(board,x,y)，表示在数独序列为board的时候，在board[x][y]位置填充元素，枚举1，2，3，4，5，6，7，8，9
        
        如果 y == 9，表示 第x行枚举完毕，我们枚举下一行，令 x+= 1, y=0
        
        如果 x == 9 说明数独序列填充完毕，返回True
        
        如果board[x][y] != '.' 说明当前位置已被赋值，我们将 y += 1
        
        否则：
            枚举board[x][y] = 1,2,3,4,5,6,7,8,9 ，如果被占用，则continue，否则把相应位置设为已占用，并dfs下一轮
        
        如果前面没有返回，最后在dfs结束时返回False.
        
        另一件事情，我们要完成几个初始化操作，思考一下，我们在玩数独游戏的时候，每个数字，在每一行，每一列，对应的九宫格中都只能出现一次
    
        我们初始化行长度为9，列长度都为10的rows与cols，如 rows[2][4]=1数独序列中的第3行中，元素4已被占用
        ols[1][5]=0，表示数独序列中的第2行中，元素5已被占用
    
        另外还有cell三维数组，cell[2][2][4] = 1,表示第3行，第3列的九宫格中，数字4被占用



```py
class Solution:
    rows = []
    cols = []
    cell = []

    def solveSudoku(self, board):
        self.rows, self.cols = [[0] * 10 for _ in range(9)], [[0] * 10 for _ in range(9)]
        self.cell = [[[0] * 10 for _ in range(3)] for _ in range(3)]
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':  # 初始化三个数组，把输入矩阵中的元素对应的标记修改为1
                    num = int(board[i][j])  # 输入的数字为字符
                    self.rows[i][num] = self.cols[j][num] = self.cell[i // 3][j // 3][num] = 1
        self.dfs(board, 0, 0)

    def dfs(self, board, x, y):
        if y == 9:
            x, y = x + 1, 0
        if x == 9:
            return True
        if board[x][y] != '.':
            return self.dfs(board, x, y + 1)
        for i in range(1, 10):  # 枚举(x,y)位置待填的数字
            if not self.rows[x][i] and not self.cols[y][i] and not self.cell[x // 3][y // 3][i]:  # 满足，说明可填
                board[x][y] = str(i)  # 填入字符，转成str形式
                self.rows[x][i] = self.cols[y][i] = self.cell[x // 3][y // 3][i] = 1  # 置为1
                if self.dfs(board, x, y + 1):
                    return True
                else:  # 回溯
                    board[x][y] = '.'
                    self.rows[x][i] = self.cols[y][i] = self.cell[x // 3][y // 3][i] = 0  # 置为1
        return False


# 测试部分，提交代码时删除此部分
if __name__ == '__main__':
    array = [["5", "3", ".", ".", "7", ".", ".", ".", "."],
             ["6", ".", ".", "1", "9", "5", ".", ".", "."],
             [".", "9", "8", ".", ".", ".", ".", "6", "."],
             ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
             ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
             ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
             [".", "6", ".", ".", ".", ".", "2", "8", "."],
             [".", ".", ".", "4", "1", "9", ".", ".", "5"],
             [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
    Solution().solveSudoku(array)
    print(array)
```
