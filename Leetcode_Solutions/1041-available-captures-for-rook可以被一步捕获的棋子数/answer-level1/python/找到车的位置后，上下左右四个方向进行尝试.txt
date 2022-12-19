### 解题思路
找到车的位置后，上下左右四个方向进行尝试

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        res=0
        for i in range(8):
            for j in range(8):
                if board[i][j]=='R':
                    mi=i
                    mj=j
                    while j-1>=0:
                        j-=1
                        if board[i][j]=='B':
                            break
                        if board[i][j]=='p':
                            res+=1
                            break
                    i=mi
                    j=mj
                    while j+1<8:
                        j+=1
                        if board[i][j]=='B':
                            break
                        if board[i][j]=='p':
                            res+=1
                            break
                    i=mi
                    j=mj
                    while i-1>=0:
                        i-=1
                        if board[i][j]=='B':
                            break
                        if board[i][j]=='p':
                            res+=1
                            break
                    i=mi
                    j=mj
                    while i+1<8:
                        i+=1
                        if board[i][j]=='B':
                            break
                        if board[i][j]=='p':
                            res+=1
                            break
        return res
```