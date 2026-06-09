### 解题思路

使用
```
1 1 1
1 0 1
1 1 1
```
进行卷积，根据结果对原数据进行修改。

小于2 ---> 死亡（0）
等于3 ---> 活过来（1）
大于3 ---> 死亡（0）

### 代码

```python3
import numpy as np
from scipy import signal
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        arr = np.array(board)
        mask = np.ones((3,3))
        mask[1, 1] = 0
        around = signal.convolve2d(arr, mask, mode='same')
        arr[around < 2] = 0
        arr[around == 3] = 1
        arr[around > 3] = 0
        for i in range(len(board)):
            for j in range(len(board[0])):
                board[i][j] = arr[i, j]
```