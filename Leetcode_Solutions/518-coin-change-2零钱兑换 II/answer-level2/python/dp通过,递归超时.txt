### 解题思路
递归实现简单,但是很容易就超时了
dp过了,但是用时内存其实还是很高

### 代码

```python
class Solution(object):
    def change(self, amount, coins):
        """
        :type amount: int
        :type coins: List[int]
        :rtype: int
        """

        coins.sort()
        #dp[i][j]代表前i个硬币凑和为j有多少种做法
        dp=[[0 for _ in range(amount+1)] for _ in range(len(coins)+1)]
        for i in dp:
            i[0]=1
        
        for i in range(1,len(coins)+1):
            for j in range(1,amount+1):
                temp=0
                k=0
                while j-k*coins[i-1]>=0:

                    temp+=dp[i-1][j-k*coins[i-1]]
                    k+=1
                dp[i][j]=temp
        # print dp
        return dp[-1][-1]




        """
        递归直接超时,那只能用dp
        coins.sort()

        if amount==0:
            return 1
        if not coins:
            return 0
        self.result=0
        def search(target,use):
            print target,use
            if target<use[0]:
                return
            if len(use)==1:
                if target%use[0]==0:

                    self.result+=1
            else:
                if target%use[0]==0:

                    self.result+=1
                i=0
                while target-i*use[0]>=use[1]:
                    search(target-i*use[0],use[1:])
                    i+=1
        search(amount,coins)
        return self.result
        """

        
                
            
```