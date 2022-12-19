class Solution:
    def checkRecord(self, n: int) -> int:
        nRec = [1,2,4,7]
        thre = 10**9 + 7
        for i in range(4,n+1):
            nRec.append(sum(nRec[i-3:i])%thre)
        return  (nRec[n]+sum(map(lambda x: (x[0]*x[1])%thre, zip(nRec[0:n], nRec[n-1::-1])))%thre)%thre

f(n) = f(n-1) + f(n-2) + f(n-3), forall n>=0
f(0) = 1, f(1) = 2, f(2) = 4

