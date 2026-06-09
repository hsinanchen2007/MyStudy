### 解题思路
1. 正常的贪心会因为一些特殊情况报错。例如：（11，9，1）贪心输出 11*1+1*8，实际是 9*2
2. 但是按贪心的思路全部遍历完和枚举(暴力)没有什么区别，肯定会超时。
3. 综合 1、2 除了贪心还需要剪枝，如果当前计算的硬币数肯定要大于已经计算过的最小硬币数，则不再往下算了。(循环判断条件增加一个 i + count < self.mincount)

### 代码

```python3
class Solution:

    def __init__(self):

        self.mincount = float("inf")

    def coinChange(self, coins, amount: int) -> int:
        if amount == 0:
            return 0

        if not coins:
            return -1

        coins.sort(reverse=True)

        self.myChange(coins, amount, 0)

        return -1 if self.mincount == float("inf") else self.mincount

    def myChange(self, coins, amount, count):
        if amount == 0:
            self.mincount = min(self.mincount, count)
            return

        if not coins:
            return

        max = amount // coins[0]

        i = max

        while i >= 0 and i+count < self.mincount:
            rest = amount - (coins[0] * i)
            self.myChange(coins[1:], rest, count + i)
            i -= 1
```