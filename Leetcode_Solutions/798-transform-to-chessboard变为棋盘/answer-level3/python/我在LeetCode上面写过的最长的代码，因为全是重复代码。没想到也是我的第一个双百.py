历时一个小时，wocao
```
class Solution(object):
    def movesToChessboard(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        m=len(board)
        n=len(board[0])
        print(m)
        print(n)
        row=[]
        col=[]
        check0=[]
        check1=[]
        for i in range(m):
            if board[i][0]==0:
                check0.append(board[i])
            else:
                check1.append(board[i])
            row.append(board[i][0])
        for i in range(1,len(check0)):
            if check0[i]!=check0[i-1]:
                return -1
        for i in range(1,len(check1)):
            if check1[i]!=check1[i-1]:
                return -1

        wocao=[[0]*m for i in range(n)]    
        for i in range(m):
            for j in range(n):
                wocao[j][i]=board[i][j]

        check0=[]
        check1=[]
        for i in range(n):
            if wocao[i][0]==0:
                check0.append(wocao[i])
            else:
                check1.append(wocao[i])
        for i in range(1,len(check0)):
            if check0[i]!=check0[i-1]:
                return -1
        for i in range(1,len(check1)):
            if check1[i]!=check1[i-1]:
                return -1
            
        for i in range(n):
            col.append(board[0][i])
        count0=row.count(0)
        count1=row.count(1)
        if abs(count0-count1)>1:
            return -1
        res=0
        if count0>count1:
            for i in range(0,len(row),2):
                if row[i]!=0:
                    res+=1
        elif count0==count1:
            row0=0
            row1=0
            for i in range(0,len(row),2):
                if row[i]==0:
                    row0+=1
                else:
                    row1+=1
            res+=min(row0,row1)
        else:
            for i in range(0,len(row),2):
                if row[i]!=1:
                    res+=1
        print(res)
        count0=col.count(0)
        count1=col.count(1)
        if abs(count0-count1)>1:
            return -1
        if count0>count1:
            for i in range(0,len(col),2):
                if col[i]!=0:
                    res+=1
        elif count0==count1:
            col0=0
            col1=0
            for i in range(0,len(col),2):
                if col[i]==0:
                    col0+=1
                else:
                    col1+=1
            res+=min(col0,col1)
        else:
            for i in range(0,len(row),2):
                if col[i]!=1:
                    res+=1
        return res
```