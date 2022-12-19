### 解题思路
记录当前最低价和最高价的索引，遍历数组，
1.当发现第i个元素比最低价还小时，计算之前的利润，如果大于之前所算的利润则更新，然后将最低价和最高价的索引更新为i，继续遍历
2.当发现第i个元素比最高价还高时，则更新最高价的索引为i

执行用时 :
40 ms, 在所有 Python3 提交中击败了96.60%的用户
内存消耗 :14.4 MB, 在所有 Python3 提交中击败了17.95%的用户

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        min_index = 0
        max_index = 0

        lenth = len(prices)

        if lenth < 1:
            return 0

        result = 0

        for i in range(lenth):
            if prices[i] > prices[max_index]:
                max_index = i
            if prices[i] < prices[min_index]:
                if prices[max_index] - prices[min_index] >= result:
                    result = prices[max_index] - prices[min_index]
                min_index = i
                max_index = i
            
        if prices[max_index] - prices[min_index] > result:
            result = prices[max_index] - prices[min_index]
        return result

```