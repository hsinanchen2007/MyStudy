用递归会超时，动态规划速度上超过50%
```
    def numTrees(self, n: int) -> int:  
        def dfs(n):#递归
            if n==0 or n==1:
                return 1
            if n==2:
                return 2
            num=0
            for i in range(n):
                num+=dfs(i)*dfs(n-1-i)
            return num
        def dp(n):#动态规划
            if n==0 or n==1:
                return 1
            if n==2:
                return 2
            a=[1]*(n+1)
            a[0]=1
            a[1]=1
            a[2]=2
            for i in range(3,n+1,1):
                num=0
                for j in range(i):
                    num+=a[j]*a[i-1-j]
                a[i]=num
            return a[n]
        return dfs(n)
```
