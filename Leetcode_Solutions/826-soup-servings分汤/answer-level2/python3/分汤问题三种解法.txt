1. 递归+备忘录：
```
class Solution:
    def soupServings(self, N: int) -> float:
        def solve(A,B):
            if (A,B) in memo:
                return memo[(A,B)]
             if A<=0 and B>0:
                ans=1
            elif A<=0 and B<=0:
                ans=0.5
            elif A>0 and B<=0:
                ans=0
            else:
                ans=0.25*(solve(A-100,B)+solve(A-75,B-25)+solve(A-50,B-50)+solve(A-25,B-75))
            memo[(A,B)]=ans
            return ans
        if N>4800:
            return 1
        memo=dict()
        return solve(N,N)
    
```
2. 数组动态规划（自下而上）：
```
class Solution:
    def soupServings(self, N: int) -> float:
        if N>4800:
            return 1
        N=N//25 if N%25==0 else N//25+1#除以25减少复杂度
        dp=[[0 for _ in range(N+1)] for _ in range(N+1)]
        dp[0][0]=0.5
        for i in range(1,N+1):
            dp[0][i]=1
        for i in range(1,N+1):
            a1=i-4 if i>=4 else 0
            a2=i-3 if i>=3 else 0
            a3=i-2 if i>=2 else 0
            a4=i-1 if i>=1 else 0
            for j in range(1,N+1):
                dp[i][j]=0.25*(dp[a1][j]+dp[a2][max(j-1,0)]+dp[a3][max(j-2,0)]+dp[a4][max(j-3,0)])
        return dp[N][N]
```
3. 数组动态规划（自上而下，由于特殊情况较多，推荐使用前两种方法）：
```
class Solution:
    def soupServings(self, N: int) -> float:#考虑情况较多，容易出错
        if N%25==0:#除以25减少复杂度
            N=N//25
        else:
            N=N//25+1
        if N==0:#N为0到3单独计算
            return 0.5
        elif N<=2:
            return 0.625
        elif N==3:
            return 0.65625
        elif N>192:#计算结果接近1，可以直接返回1。
            return 1
        d=[[0 for _ in range(N+1)] for _ in range(N+1)]
        d[N][N]=1#为了减少复杂度i大于N-4单独计算
        probability=0
        d[N-2][N-2]=0.25
        if N-6>0:
            d[N-2][N-6]=0.0625
        d[N-3][N-1]=0.25
        d[N-1][N-3]=0.25
        if N-5>0:
            d[N-3][N-5]=0.125
        if N-9>0:
            d[N-3][N-9]=0.015625
        for i in range(N-4,0,-1):
            for j in range(N,0,-1):
                if j<=N-3:
                    d[i][j]=(d[i+4][j]+d[i+3][j+1]+d[i+2][j+2]+d[i+1][j+3])/4
                elif j==N-2:
                    d[i][j]=(d[i+4][j]+d[i+3][j+1]+d[i+2][j+2])/4
                elif j==N-1:
                    d[i][j]=(d[i+4][j]+d[i+3][j+1])/4
                else:
                    d[i][j]=d[i+4][j]/4
        for j in range(N,0,-1):#i为0j不为0单独计算
            if j<=N-3:
                d[0][j]=(d[4][j]+d[3][j+1]+d[2][j+2]+d[1][j+3])/4+(d[1][j+2]+d[1][j+1]+d[2][j+1])/4+(d[1][j]+d[2][j]+d[3][j])/4
            elif j==N-2:
                d[0][j]=(d[4][j]+d[3][j+1]+d[2][j+2])/4+(d[1][j+2]+d[1][j+1]+d[2][j+1])/4+(d[1][j]+d[2][j]+d[3][j])/4
            elif j==N-1:
                d[0][j]=(d[4][j]+d[3][j+1])/4+(d[1][j+1]+d[2][j+1])/4+(d[1][j]+d[2][j]+d[3][j])/4
            else:
                d[0][j]=d[4][j]/4+(d[1][j]+d[2][j]+d[3][j])/4
            probability+=d[0][j]
        d[0][0]=d[1][1]*3/4+(d[1][2]+d[2][1])*1/2+(d[1][3]+d[2][2]+d[3][1])*1/4#i,j都为0单独计算
        probability+=d[0][0]/2
        return probability
```



