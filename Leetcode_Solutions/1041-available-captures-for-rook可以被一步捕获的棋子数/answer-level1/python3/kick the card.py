### 解题思路

punch in the card. 

Again, I will give you the code. 

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        x=0
        y=0
        for i in range(8):
            for j in range(8):
                if board[i][j]=='R':
                    x=j
                    y=i
                    break
            if x > 0 or y>0:
                break
        capture=0
        i=y
        j=x
        #up
        while j>=0:
            if board[i][j]=='B':
                break
            if board[i][j]=='p':
                capture+=1
                break
            j-=1
        j=x
        #left
        while i>=0:
            if board[i][j]=='B':
                break
            if board[i][j]=='p':
                capture+=1
                break
            i-=1
        #down
        i=y
        while j<8:
            if board[i][j]=='B':
                break
            if board[i][j]=='p':
                capture+=1
                break
            j+=1
        #right
        j=x
        while i<8:
            if board[i][j]=='B':
                break
            if board[i][j]=='p':
                capture+=1
                break
            i+=1
        return capture
```