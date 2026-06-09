### 解题思路
1. 回溯算法模版 https://leetcode-cn.com/problems/n-queens/solution/hui-su-suan-fa-xiang-jie-by-labuladong/
2. 官方题解的冲突判断方法

### 代码

```python
class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
#         def isValid(board, row, col):
#             n = len(board)
#             # 检查列是否有皇后互相冲突
#             for i in range(n):
#                 if board[i][col] == 'Q':
#                     return False
#             # 检查右上方是否有皇后互相冲突
#             r_row, r_col = row, col
#             while r_row > 0 and r_col < n - 1:
#                 r_row -= 1
#                 r_col += 1
#                 if board[r_row][r_col] == 'Q':
#                     return False
#             # 检查左上方是否有皇后互相冲突
#             l_row , l_col = row, col
#             while l_row > 0 and l_col > 0:
#                 l_row -= 1
#                 l_col -= 1
#                 if board[l_row][l_col] == 'Q':
#                     return False
#             return True

        def isValid(row, col):
            return not (cols[col] + hill_diagonals[row - col] + dale_diagonals[row + col])

        def place_queen(row, col):
            # queens.add((row, col))
            board[row][col] = 'Q'
            cols[col] = 1
            hill_diagonals[row - col] = 1
            dale_diagonals[row + col] = 1
        
        def remove_queen(row, col):
            # queens.remove((row, col))
            board[row][col] = '.'
            cols[col] = 0
            hill_diagonals[row - col] = 0
            dale_diagonals[row + col] = 0

        def backtrack(board, row):
        #     if 满足条件:
        #         res.append(路径)
        #         return
            if row == len(board):
                # tmp_list = [] #二维变一维添加到res中
                # for e_row in board:
                #     tmp = ''.join(e_row)
                #     tmp_list.append(tmp)
                # res.append(tmp_list)
                res.append([''.join(e_row) for e_row in board])
                # print(board)
                return
        #     for 选择 in 选择列表:
        #         做选择
        #         backtrack(路径,选择列表)
        #         撤销选择
            for col in range(len(board[0])):
                if not isValid(row, col):
                    # print(isValid(board, row, col))
                    continue
                # 做选择
                place_queen(row, col)
                # print(board)
                backtrack(board, row + 1)
                # 撤销选择
                remove_queen(row, col)

        res = []
        hill_diagonals = [0] * (2 * n - 1)
        dale_diagonals = [0] * (2 * n - 1)
        cols = [0] * n
        board = [['.'] * n for _ in range(n)] #初始化二维棋盘
        # print(board)
        backtrack(board, 0)
        return res
```