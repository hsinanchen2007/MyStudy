### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        coin_, l_ = {}, []
        if len(coins) == 0:
            return -1
        if amount == 0:
            return 0
        for co in coins:
            coin_[co] = 1
        for i in range(2, amount+1):
            for j in coins:
                if i <= j:
                    continue
                if i-j not in coin_:
                    continue
                l_.append(coin_[i-j])
            if len(l_) > 0 and i not in coin_:
                coin_[i] = min(l_) + 1
            l_ = []
        if amount not in coin_:
            return -1
        return coin_[amount]
```