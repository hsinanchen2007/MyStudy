### 解题思路
分四种情况，分别做dfs， memo保存重复结果

### 代码

```python3
class Solution:
    def tictactoe(self, board: List[str]) -> str:
        N = len(board)
        new_board = []
        for i in range(len(board)):
            new_board.append(["" for i in range(N)])

        for i in range(len(board)):
            for j in range(len(board[0])):
                new_board[i][j] = board[i][j]

        exists = False
        memo = {}
        for i in range(len(new_board)):
            for j in range(len(new_board[0])):
                if new_board[i][j] == " ":
                    exists = True
                    continue

                if new_board[i][j] == 'O':
                    tmp = max(self.dfs1(new_board, i, j, 'O', memo), self.dfs2(new_board, i, j, 'O', memo), self.dfs3(new_board, i, j, 'O', memo), self.dfs4(new_board, i, j, 'O', memo))

                    if tmp >= N:
                        return 'O'

                elif new_board[i][j] == 'X':
                    tmp = max(self.dfs1(new_board, i, j, 'X', memo), self.dfs2(new_board, i, j, 'X', memo), self.dfs3(new_board, i, j, 'X', memo), self.dfs4(new_board, i, j, 'X', memo))

                    if tmp >= N:
                        return 'X'

        if exists:
            return 'Pending'

        return 'Draw'

    def dfs1(self, board, i, j, target, memo):
        if i < 0 or i >= len(board):
            return 0

        if j < 0 or j >= len(board[0]):
            return 0

        if board[i][j] != target:
            return 0

        if board[i][j] == 'M':
            return 0
        
        if (i, j, target, 1) in memo:
            return memo[(i, j, target, 1)]

        board[i][j] = 'M'
        count = 1 + self.dfs1(board, i-1, j+1, target, memo) + self.dfs1(board, i+1, j-1, target, memo)
        memo[(i, j, target, 1)] = count
        board[i][j] = target
        return count

    def dfs2(self, board, i, j, target, memo):
        if i < 0 or i >= len(board):
            return 0

        if j < 0 or j >= len(board[0]):
            return 0

        if board[i][j] != target:
            return 0

        if board[i][j] == 'M':
            return 0
        
        if (i, j, target, 2) in memo:
            return memo[(i, j, target, 2)]

        board[i][j] = 'M'
        count = 1 + self.dfs2(board, i+1, j+1, target, memo) + self.dfs2(board, i-1, j-1, target, memo)
        board[i][j] = target
        memo[(i, j, target, 2)] = count
        return count

    def dfs3(self, board, i, j, target, memo):
        if i < 0 or i >= len(board):
            return 0

        if j < 0 or j >= len(board[0]):
            return 0

        if board[i][j] != target:
            return 0
        
        if (i, j, target, 3) in memo:
            return memo[(i, j, target, 3)]

        board[i][j] = 'M'

        count = 1 + self.dfs3(board, i+1, j, target, memo) + self.dfs3(board, i-1, j, target, memo)
        board[i][j] = target
        memo[(i, j, target, 3)] = count
        return count


    def dfs4(self, board, i, j, target, memo):
        if i < 0 or i >= len(board):
            return 0

        if j < 0 or j >= len(board[0]):
            return 0

        if board[i][j] != target:
            return 0

        if board[i][j] == 'M':
            return 0
        
        if (i, j, target, 4) in memo:
            return memo[(i, j, target, 4)]

        board[i][j] = 'M'
        count = 1 + self.dfs4(board, i, j+1, target, memo) + self.dfs4(board, i, j-1, target, memo)
        board[i][j] = target
        memo[(i, j, target, 4)] = count
        return count




```