### 解题思路
核心思路：F(S)=F(S-C)+1，F为总值为S的最小硬币使用次数，C为拥有的硬币面值
@functools.lru_cache(amount)：修饰器，能够缓存已经计算过的值

### 代码

```python3
import functools
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        @functools.lru_cache(amount)
        def run(S):
            if S < 0:return -1
            if S == 0:return 0
            maxc = int(1e9)
            for i in coins:
                res = run(S-i)
                if res != -1 and res<maxc:
                    maxc = res+1
            return maxc if maxc<int(1e9) else -1
        if amount < 1: return 0
        return run(amount)

```