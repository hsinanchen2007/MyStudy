```python
import numpy as np
import collections
class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        def isok(tensor):
            d = collections.Counter(list(tensor))
            for i in range(9):
                if d[str(i+1)]>1:
                    return False
            return True

        board = np.array(board)
        for i in range(9):
            if not isok(board[i]):
                return False
        for i in range(9):
            if not isok(board[:,i]):
                return False
        for i in range(9):
            x, y = i%3, i/3
            if not isok(board[x*3:(x+1)*3, y*3:(y+1)*3].flatten()):
                return False

        return True
```