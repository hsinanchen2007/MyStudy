将 之前的4个状态拓展到 2*k个状态,

需要注意的是 如果次数大于数组长的一般, 转换成任意次数的问题. 有一个测试用例会卡这里.

```python
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        []
        if k == 0:
            return 0
        if k >= len(prices)//2:
            have, nothave, res = float('-inf'), 0, 0
            for price in prices:
                prehave = have
                prenothave = nothave
                have = max(prehave, prenothave - price)
                nothave = max(prehave + price, prenothave)
            return nothave

        buys = [float('-inf')] * k
        res = 0
        sells = [0] * k
        for price in prices:
            pbuys = buys[:]
            psells = sells[:]
            for i in range(k):
                if i == 0:
                    buys[i] = max(pbuys[i], -price)
                else:
                    buys[i] = max(psells[i - 1] - price, pbuys[i])
                sells[i] = max(psells[i], pbuys[i] + price)
                res = max(res, sells[i])
        return res

```