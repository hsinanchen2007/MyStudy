时间有点长
```
class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        #You want to see if they contain the same elements, but don't care about the order.
        res=[]
        def com_List(S,x,y):
            for i in range(x):
                for j in range(n):
                    # print i,j,x,y, y==j,abs(i-x)==abs(j-y)
                    if S[i][j]=='Q' and(y==j or abs(i-x)==abs(j-y)):
                        return False
            return True
        S = [['.' for i in range(n)]for j in range(n)]
        def generate(S=S,row=0):
            if row>=n:
                List=[]
                for i in range(len(S)):
                    List.append(''.join(S[i]))
                res.append(List)
            for i in range(n):
                if com_List(S,row,i) :
                    for j in range(n):
                        S[row][j]= '.'
                    S[row][i]='Q'
                    generate(copy.deepcopy(S),row+1)
                else:
                    continue
        generate()
        return res
```
