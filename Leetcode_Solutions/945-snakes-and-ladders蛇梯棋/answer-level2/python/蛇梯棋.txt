先转成一维，再使用广度优先遍历




class Solution(object):
    def snakesAndLadders(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        N=len(board)
        path=[]
        
        for ii in range(N):
            if ii%2==0:
                path+=board[N-1-ii]
            else:
                for jj in range(N-1,-1,-1):
                    path.append(board[N-1-ii][jj])
        
        col=set()
        col.add(0)
        
        for ii in range(1,N*N+1):
            temp=set()
            for jj in col:
                if (jj+6)>=(N*N-1):
                    return ii
                
                for kk in range(jj+1,jj+7):
                    v=path[kk]
                    if v==-1:
                        temp.add(kk)
                    else:
                        temp.add(v-1)
            col=temp
            if (N*N-1) in col:
                return ii
        return -1

时间战胜83%，存储战胜100%