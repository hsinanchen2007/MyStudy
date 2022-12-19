执行用时 :
196 ms
, 在所有 Python3 提交中击败了
100.00%
的用户

内存消耗 :
13.8 MB
, 在所有 Python3 提交中击败了
16.00%
的用户
```
class Solution:
    def knightProbability(self, N: int, K: int, r: int, c: int) -> float:
        probability=[[[0 for _ in range(N)] for _ in range(N)] for _ in range (K+1)]#利用3维数组降低时间复杂度
        probability[0][r][c]=1
        for i in range(K):
            for j in range(N):
                for k in range(N):
                    if probability[i][j][k]:
                            if -1<j+1<N and -1<k+2<N:
                                probability[i+1][j+1][k+2]+=probability[i][j][k]*0.125
                            if -1<j+2<N and -1<k+1<N:
                                probability[i+1][j+2][k+1]+=probability[i][j][k]*0.125
                            if -1<j+2<N and -1<k-1<N:
                                probability[i+1][j+2][k-1]+=probability[i][j][k]*0.125
                            if -1<j+1<N and -1<k-2<N:
                                probability[i+1][j+1][k-2]+=probability[i][j][k]*0.125
                            if -1<j-1<N and -1<k-2<N:
                                probability[i+1][j-1][k-2]+=probability[i][j][k]*0.125
                            if -1<j-2<N and -1<k-1<N:
                                probability[i+1][j-2][k-1]+=probability[i][j][k]*0.125
                            if -1<j-2<N and -1<k+1<N:
                                probability[i+1][j-2][k+1]+=probability[i][j][k]*0.125
                            if -1<j-1<N and -1<k+2<N:
                                probability[i+1][j-1][k+2]+=probability[i][j][k]*0.125
        p=0
        for i in range(N):
            for j in range(N):
                p+=probability[K][i][j]
        return p
```
