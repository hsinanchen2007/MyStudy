### 解题思路

每一个位置本来只有0， 1两种情况，但是需要记录信息，可以利用数的高位来存其状态，
由于每一个位置只有两种状态，所以直接利用一位就可以记录。

然后再遍历一遍，将状态取出来即可。

时间复杂度`O(n*M)` 
空间复杂度`O(1)`


### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        n = len(board)
        if n == 0:
            return 
        m = len(board[0])
        
        dirs = [[-1, -1],
                [-1, 0],
                [-1, 1],
                [0, -1],
                [0, 1],
                [1, -1],
                [1, 0],
                [1, 1]]
        
        def cal(i, j):
            tmp = 0
            for x in dirs:
                _i = i + x[0]
                _j = j + x[1]
                if _i >= 0 and _i < n and _j >= 0 and _j < m and (board[_i][_j] & 1):
                    tmp += 1
            if board[i][j] == 1 and tmp in [2, 3] or board[i][j] == 0 and tmp == 3:
                board[i][j] = board[i][j] | (1 << 1)
        
        
        for i in range(n):
            for j in range(m):
                cal(i, j)
        for i in range(n):
            for j in range(m):
                board[i][j] = board[i][j] >> 1
        
                    
```