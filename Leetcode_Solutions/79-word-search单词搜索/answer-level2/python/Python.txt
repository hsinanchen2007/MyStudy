### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def exist(self, board, word):

        row=len(board)
        if row==0:
            return False
        col=len(board[0])
        directs=[[0,1],[0,-1],[-1,0],[1,0]]
        def help(i,j,signal,word):
            if len(word) == 0:
                return True
            for direct in directs:
                cur_i=i+direct[0]
                cur_j=j+direct[1]
                if cur_i>=0 and cur_i<row and cur_j>=0 and cur_j<col and board[cur_i][cur_j]==word[0]:
                    if signal[cur_i][cur_j]==1:
                        continue
                    signal[cur_i][cur_j]=1
                    if help(cur_i,cur_j,signal,word[1:])==True:
                        return True
                    else:
                        signal[cur_i][cur_j]=0
            return False



        signal=[[0 for _ in range(col)]for _ in range (row)]

        for i in range(row):
            for j in range(col):
                if board[i][j]==word[0]:

                    signal[i][j]=1
                    if help(i,j,signal,word[1:])==True:
                        return True
                    else:
                        signal[i][j]=0
        return False
```