```
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        # _*_ coding:gbk _*_
        List = []
        for i in range(n,n*(n+1),n):
            list1 = [0 for j in range(i-n+1,i+1)]
            List.append(list1)
        kkk,ii,jj = 0,0,n
        while True:
            kk = 1
            n1 = 4 * n - 2 + 2 * kkk
            for x in range(ii,jj):
                List[ii][x] = kk + kkk
                if x != ii:
                    List[x][ii] = n1 - List[ii][x]
                kk += 1
            if jj - ii <= 1:
                return(List)
            tt = 0
            for l in range(ii,jj):
                List[-ii-1][l] = List[-ii-1][ii] - tt 
                List[l][-ii-1] = n1 - List[-ii-1][l] 
                tt += 1
            kkk = kkk + 4 * (n -1)
            n = n - 2
            ii += 1
            jj -= 1
```
