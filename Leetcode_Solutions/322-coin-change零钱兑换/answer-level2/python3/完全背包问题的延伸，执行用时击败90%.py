### 解题思路
根据完全背包问题演化而来，普通的0-1背包问题中单个物品的数量不能重复，而完全背包问题中物品数量可以重复，这一点正对应着Coin Change问题中每一个面值可以重复选择。因此，coins对应着背包问题中的物品体积，amount对应着背包的总体积。
需要强调的是：1.本问题中的零钱必须完全兑开，意味着背包必须装满，否则返回-1。2.不同于以往的优化目标：最大化背包最终所装物品的总价值，零钱兑换的目标是：最小化零钱的数目。因此构造了一个与coins等长的全1列表，作为每个零钱对应的价值，从而达最小化零钱数目的目标。3.完全背包问题的初始化数列dp1首位是0，后面为正无穷，可以达到若无法恰好兑换，则返回数目为正无穷的目的。
最后，关于绿色注释，解注释之后可以输出题目中explanation中的内容，即将零钱兑换的公式：大钱拆分成小钱的等式。可以进一步帮助理解题目。


### 代码

```python3
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # n:len of coins, v:amount, vs:coins[1,2,5], ps:[1,1,1] 
        def ns(n,v,vs,ps):
            dp1=[0]+[float("inf")]*v
            #dp2=['']*(v+1)
            for i in range(n):
                for j in range(vs[i],v+1):
                    if dp1[j]>dp1[j-vs[i]]+ps[i]:
                        dp1[j]=dp1[j-vs[i]]+ps[i]# find min
                        #dp2[j]=dp2[j-vs[i]]+'+'+str(vs[i])
                #print(dp1)
            #print(str(v)+"="+dp2[-1][1:])
            if dp1[-1]==float("inf"):
                return -1
            return dp1[-1] 
        n=len(coins)
        ps = [1]*n
        return ns(n,amount,coins,ps)
                        
                    


        
```