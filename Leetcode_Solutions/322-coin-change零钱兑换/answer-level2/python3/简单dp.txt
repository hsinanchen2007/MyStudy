### 解题思路
此处撰写解题思路

### 代码

```python3

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if not coins or amount < 0:
            return 0
        # 最小硬币个数
        # 钱数为i的时候 的最小硬币数  # min_coin[i]
        coin_min = [amount+1 for n in range(amount + 1)]
        coin_min[0] = 0
        for i in range(1, amount + 1):
            for j in range(len(coins)):
                if i >= coins[j]:
                    coin_min[i] = min(coin_min[i], coin_min[i - coins[j]] + 1)
        return -1 if coin_min[amount] > amount else coin_min[amount]

```