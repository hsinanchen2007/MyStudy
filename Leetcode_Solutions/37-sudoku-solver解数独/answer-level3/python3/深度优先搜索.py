```
class Solution:
    def __init__(self):
        self.row_set = [set() for _ in range(9)]
        self.col_set = [set() for _ in range(9)]
        self.nn_set = [set() for _ in range(9)]
        self.empty = []

    def solveSudoku(self, board: list) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        for i, row in enumerate(board):
            for j, n in enumerate(row):
                if n == ".":
                    self.empty.append((i, j))

                self.row_set[i].add(n)
                self.col_set[j].add(n)
                self.nn_set[(i // 3) * 3 + (j // 3)].add(n)

        self.dfs(board)

    def dfs(self, board):
        if len(self.empty) == 0:
            return True

        nums = {str(i) for i in range(1, 10)}

        i, j = self.empty[0][0], self.empty[0][1]
        nums -= self.row_set[i]
        nums -= self.col_set[j]
        nums -= self.nn_set[(i // 3) * 3 + (j // 3)]

        if len(nums) == 0:
            return False
        for n in nums:
            self.row_set[i].add(n)
            self.col_set[j].add(n)
            self.nn_set[(i // 3) * 3 + (j // 3)].add(n)
            self.empty.pop(0)
            board[i][j] = n

            if self.dfs(board):
                return True
            else:
                self.row_set[i].remove(n)
                self.col_set[j].remove(n)
                self.nn_set[(i // 3) * 3 + (j // 3)].remove(n)
                self.empty.insert(0, (i, j))
                board[i][j] = "."

        return False
```