### 解题思路

1. 当送出的快递数小于总数N时, 现在就还可能送快递, 且剩余还未送出的快递中的任何一个都可能现在被送出
2. 当接受的快递数小于送出的快递数时, 现在就还可能收快递, 且已送出而没收到的快递中的任何一个都可能现在被收到
3. 当所有快递都被送出而只剩一个快递还没收到的时候, 就只剩一种可能了

### 代码

```python
import functools

class Solution:
    def countOrders(self, n: int) -> int:
        @functools.lru_cache(maxsize=1000)
        def backtrack(delivery: int, pickup: int, count: int) -> int:
            if delivery == n and pickup == n - 1:
                return 1
            add = 0
            if delivery < n:
                add += (n - delivery) * backtrack(delivery + 1, pickup, count)
            if pickup < delivery:
                add += (delivery - pickup) * backtrack(delivery, pickup + 1, count)
            return (count + add) % (10 ** 9 + 7)

        return backtrack(0, 0, 0)
```