### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ##借鉴最大子数组思路，采用双指针法
        res = 0
        tmp = 0
        i = 0
        while i < len(prices)-1:
            for j in range(i+1,len(prices)):
                tmp = prices[j] - prices[i]
                if tmp > res:
                    res = tmp
                if tmp < 0:
                    tmp = 0
                    i = j
                    break
            else:
                break
        return res
```