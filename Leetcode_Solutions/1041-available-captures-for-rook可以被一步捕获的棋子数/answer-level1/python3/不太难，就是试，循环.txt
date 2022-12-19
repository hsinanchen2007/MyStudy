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
        m=len(board)
        n = len(board[0])
        print(m,n)
        sin = 0
        for i in range(m):
            for j in range(n):
                if board[i][j] =='R':
                    sin = 1
                    break
            if sin == 1:
                break
        a = []
        b = []
        print(i,j)
        for k in range (8):
            a.append(board[i][k])
        for k in range (8):
            b.append(board[k][j])
       # a = board[i][:]
       # b = board[:][j]
        print(a,b)
        #B = [] 
        count = 0
        for k in range(j+1,len(a),1):
            if a[k] == 'B':
                break
            if a[k] == 'p':
                count +=1
                break
        for k in range(j-1,-1,-1):
            if a[k] == 'B':
                break
            if a[k] =='p':
                count  += 1
                break
        for k in range(i+1,len(b),1):
            if b[k] == 'B':
                break
            if b[k] =='p':
                count  += 1
                break
        for k in range (i-1,-1,-1):
            if b[k] =='B':
                break
            if b[k] =='p':
                count = count+1
                break
        return count
        

                






```