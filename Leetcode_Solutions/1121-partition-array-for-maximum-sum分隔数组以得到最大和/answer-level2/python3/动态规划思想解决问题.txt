动态规划问题求解的条件：最优解的表示；状态转移方程；边界条件判断。

对于此问题：
1.最优解表示：res[i] 表示 A[0:i]的最优划分对应的值和（res[len(A)]即最终结果）；
2.状态转移方程：res[i]=res[i-len(lastSubA)]+max(lastSubA)*len(lastSubA) ,1<= len(lastSubA) <=k.  lastSubA表示A[0:i]的最优划分的最后一个子数组
3.边界条件判断：res[i]=max(A[0:i])*i , 1 <= i <= k

编程实现（参考的别人的代码）：
```
def maxSumAfterPartitioning3(self, A, K) :
        n=len(A)
        res=[0]*(n+1)
        for i in range(1,n+1) :
            j=i-1
            mx=float("-inf")
            while i-j <= K and j >= 0 :
                #由于不知道lastSubA的大小，因此对lastSubA的所有可能都进行计算，取最大的
                mx=max(mx,A[j])
                res[i]=max(res[i],res[j]+mx*(i-j)) 
                j-=1
        return res[n]
```

