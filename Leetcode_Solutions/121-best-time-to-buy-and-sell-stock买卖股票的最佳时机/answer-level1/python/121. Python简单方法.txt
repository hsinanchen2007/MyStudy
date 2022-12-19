### 解题思路
实际上问题就是求一个区间，使得区间左边边界尽量小，区间右边界尽量大，这样可以使得差值最大，我们只需要记录以某个位置为中心，左边的最小值和右边的最大值即可。

### 代码

```python
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if prices == []:
            return 0
        length = len(prices)
        min_left = [0] * length
        max_right = [0] * length 
        min_left[0] = prices[0]
        max_right[-1] = prices[-1]
        for i in range(1, length):
            min_left[i] = min(min_left[i - 1], prices[i])
        for i in range(length - 2, -1, -1):
            max_right[i] = max(max_right[i + 1], prices[i])
        max_num = 0
        for i in range(length):
            temp = max_right[i] - min_left[i]
            if temp > max_num:
                max_num = temp

        return max_num
```