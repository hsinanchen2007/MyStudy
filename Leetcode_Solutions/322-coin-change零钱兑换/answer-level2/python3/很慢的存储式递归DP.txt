### 解题思路

### 状态转移方程：
finMin(amount)=1+min(finMin(amount-lis[0]),finMin(amount-lis[1]),...,finMin(amount-lis[len(lis)-1]))
然后用dp记录已经做过的工作。 
运行结果就是，第一次转移很慢，以后就非常快了。

### 代码


```
class Solution:
    def coinChange(self, lis: List[int], amount: int) -> int:
        if amount==0:return 0
        dp=[None for i in range(amount+1)]
        return self.finMin(lis,amount,dp)
    def finMin(self,lis,amount,dp):
        if amount<=0:return -1
        if dp[amount]!=None:
            return dp[amount]
        if amount in lis:
            dp[amount]=1
            return 1
        minN=float('inf')
        for i in range(len(lis)):
            tmp=1+self.finMin(lis,amount-lis[i],dp)
            if tmp!=0 :
                minN= minN if minN<tmp else tmp
            else:continue
        if minN==float('inf'):
            dp[amount]=-1
            return -1
        else:
            dp[amount]=minN
            return minN
#ends
```
