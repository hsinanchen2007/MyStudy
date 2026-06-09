### 解题思路
拷贝一个数组，遍历每个位置，使用方向数组计算出周围的最多8个位置，按规则更新数组

### 代码

```python3
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])
        copy_board = [[board[row][col] for col in range(n)] for row in range(m)]
        tem = [(-1,-1),(-1,0),(-1,1),(0,-1),(0,1),(1,-1),(1,0),(1,1)]
        for i in range(m):
            for j in range(n):
                # while(i-1>=0 and i+1<m and j-1>=0 and j+1<n):
                sum = 0
                for k in tem:
                    r = i+k[0]
                    c = j+k[1]
                    if(r>=0 and r<m and c>=0 and c<n):
                        sum+=copy_board[r][c]
                if (copy_board[i][j] == 0):
                    if (sum == 3):
                        board[i][j] = 1
                else:
                    if (sum < 2 or sum > 3):
                        board[i][j] = 0





```