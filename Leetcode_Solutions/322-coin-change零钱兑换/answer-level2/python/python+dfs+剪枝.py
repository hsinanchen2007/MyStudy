### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    res = float('inf')
    def coinChange(self, coins: List[int], amount: int) -> int:
        """
        dfs 
        """
        coins.sort(reverse=True)
        def dfs(amount, begin, count):
            if amount==0:
                self.res = min(self.res, count)
                return
            if begin==len(coins):
                return
            for n in range(amount//coins[begin], -1, -1):
                if count+n>=self.res:
                    # 大的不换换小的硬币数量肯定更多，所以不用往下换了
                    break
                dfs(amount-n*coins[begin], begin+1, count+n)
        dfs(amount, 0, 0)
        return self.res if self.res<float('inf') else -1
        
```