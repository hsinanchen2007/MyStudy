### 解题思路
先找到R位置，再计算各个路径的黑卒

### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        for i in range(len(board)):
            try:
                j=board[i].index("R")
                k=i
            except:
                pass

        count=0
        for i in range(j,-1,-1):
            if board[k][i]=="B":
                break
            elif board[k][i]=="p":
                count=count+1
                break
        for i in range(j,len(board),1):
            if board[k][i]=="B":
                break
            elif board[k][i]=="p":
                count=count+1
                break
        for i in range(k,-1,-1):
            if board[i][j]=="B":
                break
            elif board[i][j]=="p":
                count=count+1
                break
        for i in range(k,len(board),1):
            if board[i][j]=="B":
                break
            elif board[i][j]=="p":
                count=count+1
                break
        return count
```