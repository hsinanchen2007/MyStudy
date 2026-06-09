```
class Solution:
    def shortestSuperstring(self, A: List[str]) -> str:
        n = len(A)
        weight =[[0 for i in range(n)]for j in range(n)]
        str_= [[0 for i in range(n)]for j in range(n)]    #str_[i][j]从i到j，i除掉公共部分后，剩余部分。

        def dist(a,b,k,l):
            # print(k,l)
            n = len(b)
            c = a[-1]
            lenth1 = len(a)
            if c not in b:
                # print(k,l)
                str_[k][l] = a[:]
                return n
            for i in range(n-1,-1,-1):
                if b[i] == c:
                    if a.endswith(b[:i+1]):
                        lenth = len(b[:i+1])
                        str_[k][l] = a[:lenth1-lenth]
                        # print(a[:lenth1-lenth],k,l,lenth,b[:i+1])
                        return n-i-1
            str_[k][l] = a[:]
            return n

        for i in range(n):
            for j in range(n):
                if i==j:
                    continue
                weight[i][j] = dist(A[i],A[j],i,j)
        # print(str_)
        
        dp = [[float('inf') for j in range(n)]for i in range(1<<n)]
        # parent = [[-1 for j in range(n)]for i in range(1<<n)]
        dp[0][:]= [0 for i in range(n)]
        for i in range(n):
            str_
            dp[1<<i][i] = len(A[i])

        for i in range(1<<n):
            for j in range(n):
                if (i>>j)&1:
                    for k in range(n):
                        if (i-(1<<j)>>k)&1:
                            if dp[i][j]>dp[i-(1<<j)][k]+weight[k][j]:
                                dp[i][j] = dp[i-(1<<j)][k]+weight[k][j]
                                # parent[i][j] = k
                            # dp[i][j] = min(dp[i][j],dp[i-(1<<j)][k]+weight[k][j])
        i = (1<<n)-1
        j = dp[-1].index(min(dp[-1]))
        last = -1
        path = []
        while dp[i][j] != last:
            for k in range(n):
                if (i-(1<<j)>>k)&1:
                    if dp[i][j]==dp[i-(1<<j)][k]+weight[k][j]:
                        path.append(j)
                        i = i-(1<<j)
                        j = k
                        break
                else:
                    last = dp[i][j] 
        path.append(j)
        print(path)
        res =''
        for i in range(n-1,0,-1):
            res = res+str_[path[i]][path[i-1]]
        return res+A[path[0]]
```
