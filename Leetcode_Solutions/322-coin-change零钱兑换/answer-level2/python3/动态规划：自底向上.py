### 解题思路
假设输入不同面额的硬币 coins = [coin1, coin2, coin3] , 总金额 amount
递推公式：
f(0) = 0
f(coin1) = 1
f(coin2) = 1
f(coin3) = 1
f(n) = min(f(n), f(n-coin1) + 1, f(n-coin2) + 1, f(n-coin3) + 1)

注意初始状态应该取到无穷大：
f(n) = [float("inf")] * (amount+1)
f(0) = 0

### 代码

```python3
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        cnt_list = [float("inf")] * (amount+1)
        cnt_list[0] = 0

        for coin in coins:
            for i in range(coin, amount+1):
                cnt_list[i] = min(cnt_list[i], cnt_list[i-coin] + 1)
                
        if cnt_list[-1] == float("inf"):
            return -1
        else:
            return cnt_list[-1]


```