### 解题思路
自顶而下，不断递归下去，结束条件是总额为零或者总额为负。

### 代码

```python3
import functools
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        @functools.lru_cache(None)
        def dfs(n):
            if n==0:
                return 0
            if n<0:
                return -1
            res=float('inf')
            for i in coins:
                t=dfs(n-i)
                if t==-1:
                    continue
                res=min(res,t+1)
            return res if res!=float('inf') else -1    
        return dfs(amount)
       
    

```