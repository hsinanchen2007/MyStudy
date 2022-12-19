```
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        import numpy as np
        board = np.array(board)
        board_T = board.T
        a = np.argwhere(board == 'R')
        a = np.squeeze(a)
        b1 = board[a[0]]
        b2 = board_T[a[1]]
        def xunzhao(l,m,n,s,count):
            for i in range(m, n, s):
                if l[i] == 'B':
                    break
                elif l[i] == 'p':
                    count += 1
                    break
            return count
        count = 0
        return xunzhao(b1,a[1],-1,-1,count)+xunzhao(b1,a[1],len(b1),1,count)\
            +xunzhao(b2,a[0],-1,-1,count)+xunzhao(b2,a[0],len(b2),1,count)

```
