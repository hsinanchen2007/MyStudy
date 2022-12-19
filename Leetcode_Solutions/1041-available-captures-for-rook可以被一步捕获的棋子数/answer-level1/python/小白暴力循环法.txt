### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        k = 0
        def find(item):
            """
            发现车的位置
            """
            place = []
            for i in range(8):
                for j in range(8):
                    if item[i][j]=='R':
                        place = [i]+[j]
                        break
            return place
        
        star=find(board)# star[0],所在行，star[1],所在列
        for i in range(star[0]-1,-1,-1):
            if board[i][star[1]] == 'B':
                break
            elif board[i][star[1]] == 'p':
                k+=1
                break
        for i in range(star[0]+1,8,1):
            if board[i][star[1]] == 'B':
                break
            elif board[i][star[1]] == 'p':
                k+=1
                break
        for i in range(star[1]-1,-1,-1):
            if board[star[0]][i] == 'B':
                break
            elif board[star[0]][i] == 'p':
                k+=1
                break
        for i in range(star[1]+1,8,1):
            if board[star[0]][i] == 'B':
                break
            elif board[star[0]][i] == 'p':
                k+=1
                break
        return k

```