python3思路：
直接用exception 把那些出现IndexError的点去掉就好了，不用费心思去划分加判断，唯一要注意的是python的list是可以读到index为负数的值的，实际上就是往后读嘛，所以这里要加一个判断。


```
class Solution:
    def gameOfLife(self, board) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        for i in range(len(board)):
            for j in range(len(board[i])):
                live=0
                try:
                    l_1=board[i-1][j-1]
                    if l_1>0 and i>0 and j>0:
                        live+=1
                except IndexError:
                    pass
                try:
                    l_2=board[i-1][j]
                    if l_2>0 and i>0:
                        live+=1
                except IndexError:
                    pass
                try:
                    l_3=board[i-1][j+1]
                    if l_3>0 and i>0:
                        live+=1
                except IndexError:
                    pass
                try:
                    l_4=board[i][j-1]
                    if l_4>0 and j>0:
                        live+=1
                except IndexError:
                    pass
                try:
                    l_5=board[i][j+1]
                    if l_5>0:
                        live+=1
                except IndexError:
                    pass
                try:
                    l_6=board[i+1][j-1]
                    if l_6>0 and j>0:
                        live+=1
                except IndexError:
                    pass
                try:
                    l_7=board[i+1][j]
                    if l_7>0:
                        live+=1
                except IndexError:
                    pass
                try:
                    l_8=board[i+1][j+1]
                    if l_8>0:
                        live+=1
                except IndexError:
                    pass            
                if board[i][j]>0:
                    if live<2 or live>3:
                        board[i][j]=2
                    elif live==2 or live==3:
                        board[i][j]=1
                else:
                    if live==3:
                        board[i][j]=-1
                        
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j]==2:
                    board[i][j]=0
                if board[i][j]==-1:
                    board[i][j]=1
```
