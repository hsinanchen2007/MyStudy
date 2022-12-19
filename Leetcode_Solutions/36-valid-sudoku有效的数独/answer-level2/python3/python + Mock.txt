```python
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def judge(i, j):
            # judge validation between (i, j) -> (i + 2, j + 2)
            dic = collections.defaultdict(int)
            for offset_x in range(3):
                for offset_y in range(3):
                    x, y = i + offset_x, j + offset_y
                    ch = board[x][y]
                    if ch.isdigit():
                        if ch in dic: return False
                        dic[ch] = 1
            return True
        def judge_row(row):
            dic = collections.defaultdict(int)
            for j in range(len(board[0])):
                if board[row][j].isdigit() == False: continue
                if board[row][j] in dic: return False
                dic[board[row][j]] = 1
            return True
        def judge_col(col):
            dic = collections.defaultdict(int)
            for i in range(len(board)):
                if board[i][col].isdigit() == False: continue
                if board[i][col] in dic: return False
                dic[board[i][col]] = 1
            return True

        for i in range(len(board)):
            if judge_row(i) == False or judge_col(i) == False: 
                return False
        for i in range(0, len(board), 3):
            for j in range(0, len(board), 3):
                if not judge(i, j): 
                    return False
        return True

```