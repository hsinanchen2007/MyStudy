把矩阵扩大，免去边界判断,然后扫描直接深搜，深搜递归一般都要在参数里记录路径
```
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m,n=len(board),len(board[0])
        for i in range(m):
            board[i]=['']+board[i]+['']
        board=[['']*(n+2)]+board+[['']*(n+2)]
        
        l=len(word)
        cut=False#剪枝信号
        def f(x,y,i,t):#x,y扫描到的坐标，i已经匹配到的长度，t深搜路径
            nonlocal cut
            if i==l or cut:
                cut=True
                return True
            elif board[x][y]==word[i] and ((x,y) not in t):#路径判重
                return f(x+1,y,i+1,t+[(x,y)]) or f(x-1,y,i+1,t+[(x,y)]) or f(x,y+1,i+1,t+[(x,y)]) or f(x,y-1,i+1,t+[(x,y)])
            else:
                return False
        
        for i in range(1,m+1):
            for j in range(1,n+1):
                if f(i,j,0,[]):
                    return True
        return False
```
