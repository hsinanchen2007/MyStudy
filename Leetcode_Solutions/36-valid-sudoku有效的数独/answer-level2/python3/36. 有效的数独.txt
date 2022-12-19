### 解题思路
时间复杂度O(n^3)，在这个固定的数独里n是9。

### 代码

```python3
import numpy as np

class Solution:
    def isValidSudoku(self, board) -> bool:
        board = np.array(board)
        long = width = 9
        for i in range(long):
            for j in range(width):
                element = board[i,j]
                if element == '.':
                    continue
                tmp = np.copy(board[i,:])
                tmp[j] = -1
                if element in tmp:
                    print(i, j)
                    return False
                tmp = np.copy(board[:,j])
                tmp[i]=-1
                if element in tmp:
                    print(i, j)
                    return False
                tmp=np.copy(board[i // 3 * 3:i // 3 * 3 + 3,j // 3 * 3:j // 3 * 3 + 3])
                tmp[i%3,j%3]=-1
                if element in tmp:
                    print(i,j)
                    return False
        return True

```