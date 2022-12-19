### 解题思路
此处撰写解题思路
写的丑了点，然后感觉这道题目也是有点不明所以。第三个例子就很奇怪，为啥不可以捕获5个，初以为要dfs或者bfs，
但是这样向四周扩散会多余不必要的单元格的查询，所以直接在R的四个方向上查找就可以了。
### 代码

```python3
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        ans = 0
        for i in range(8):
            for j in range(8):
                if board[i][j]=='R':
                    r,c = i+1,j+1
                    while c<8 and board[i][c]!='B':                        
                        if board[i][c]=='p':
                            ans+=1
                            break
                        c+=1
                    c = j-1
                    while 0<=c and board[i][c]!='B':                        
                        if board[i][c]=='p':
                            ans+=1
                            break
                        c-=1

                    while r<8 and board[r][j]!='B':                        
                        if board[r][j]=='p':
                            ans+=1
                            break
                        r+=1

                    r = i-1
                    while 0<=r and board[r][j]!='B':                        
                        if board[r][j]=='p':
                            ans+=1
                            break
                        r-=1                    
        return ans
```