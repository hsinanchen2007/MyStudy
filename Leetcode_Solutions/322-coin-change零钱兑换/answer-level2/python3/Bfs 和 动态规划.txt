### 解题思路
这道题的bfs方法和279号题方法相同,但是时间太慢,就不说了.
动态规划时间也就凑合

### 代码

```python3
#dp
class Solution:
    def coinChange(self, coins: [int], amount: int) -> int:
        if amount==0:
            return 0
        include=[float('inf') for _ in range(amount+1)]#开始时候将从0到amount的所有值需要的硬币都设置为无穷大
        include[0]=0
        coins.sort(reverse=-1) #将硬币从大到小排列
        def dp(tar):
            for i in coins:
                mid=tar-i
                if mid>=0:
                    include[tar]=min(include[tar],include[mid]+1)
            return

        for i in range(1,amount+1):
            dp(i)
        return include[amount] if include[amount]!=float('inf') else -1 #如果这个值需要的硬币为inf,表示没有数值能够满足,返回-1


#bfs
class Solution:
    def coinChange(self, coins: [int], amount: int) -> int:
        if amount==0:
            return 0
        coins.sort(reverse=-1)
        include=set() #存储已经计算过的数字,避免重复计算
        que=[amount] #队列,用于实现bfs
        res=0 #存储金额个数
        while que:
            n = len(que)
            res+=1
            for i in range(n):
                top=que.pop(0)
                if top not in include:
                    include.add(top)
                    for i in coins:
                        mid=top-i
                        if mid==0:
                            return res
                        elif mid>0:
                            que.append(mid)
        return -1
```