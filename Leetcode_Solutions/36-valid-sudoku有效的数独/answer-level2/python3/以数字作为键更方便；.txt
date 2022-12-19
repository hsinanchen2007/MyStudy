```
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        board_dict = {str(num): [] for num in range(1, 10)}
        for i, row in enumerate(board):
            for j, ele in enumerate(row):
                if ele is not '.':
                    section = (i // 3, j // 3) 
                    for index in board_dict[ele]:
                        if i == index[0] or j == index[1] or section == index[2]:
                            return False
                    idx = (i, j, section)
                    board_dict[ele].append(idx) 
        return True
                        
                        
```
