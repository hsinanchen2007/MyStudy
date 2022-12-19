### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def numRookCaptures(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        x,y,n=0,0,0
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j]=="R":
                    x=i
                    y=j
        for d in range(1,x):
            if board[x-d][y]=="p" :
                n+=1
                break
            if board[x-d][y]=="B":
               break
        for d in range(1,8-x):
            if board[x+d][y]=="p":
                n+=1
                break
            if board[x+d][y]=="B":
                break
        for d in range(1,y):
            if board[x][y-d]=="p":
                n+=1
                break
            if board[x][y-d]=="B":
                break
        for d in range(1,8-y):
            if board[x][y+d]=="p":
                n+=1
                break
            if board[x][y+d]=="B":
                break
        return n
```