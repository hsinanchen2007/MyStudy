- 一个朴素的思想就是从`1 ~ max(piles)`一个一个尝试
- 但是会发现时间为`O(H*N)`肯定超时
- 自然想到使用二分，再看看时间复杂度`O(N*logH)`，可以通过

```python
class Solution:
    def minEatingSpeed(self, piles, H: int) -> int:

        def possible(k):
            t = 0
            for p in piles:
                t += p // k
                if p % k != 0:
                    t += 1
            return t <= H

        l = 1  # 搜索下限不是min(pile)
        r = max(piles)
        while l < r:
            mid = l + (r - l) // 2
            if possible(mid):  # 要返回的是第一个满足条件的数，这里就是第一个满足H时间内吃完的数
                r = mid
            else:
                l = mid + 1
        return r
```