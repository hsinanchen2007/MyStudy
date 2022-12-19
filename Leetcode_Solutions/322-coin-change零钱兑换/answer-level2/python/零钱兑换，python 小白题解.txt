
```
```python []
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        #输出dic[i]表示凑出i元的最小硬币数
        #例子中分别用1元，2元，5元，res=min(1+dic[10],1+dic[9],1+dic[6])
        #动态规划，思考特殊解，dic[1]、dic[2]、dic[5]=1
        #dic[3]=min(1+dic[1],1+dic[2]),然后dic[4]，从dic[0]到dic[11]这些结果逐个保存，最后算出dic[11]
        dic={}
        dic[0]=0
        #初始化，先默认都凑不到，除了dic[0]全是-1
        for i in range(1,amount+1):
            dic[i]=-1
        for n in range(1,amount+1):
            for coin in coins:
                #要凑的钱n，从小到大排序，先把coin=n的情况计算出来，这时候n-coin=0，dic[n-coin]=0
                #如果遍历coins，发现[2,4],5这种dic[n-coin]=-1，凑不出来，刚好输出dic[5]=-1
                if coin<=n and dic[n-coin]!=-1:
                    temp=1+dic[n-coin]
                    if dic[n]==-1:
                        dic[n]=temp
                    else:
                        if temp<dic[n]:
                            dic[n]=temp
        return dic[amount]
    
