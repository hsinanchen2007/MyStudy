### 解题思路
此处撰写解题思路

### 代码

```python
class Solution:
    def maxProfit(self, prices):
        """
        单调栈
        """
        res = 0
        stack = []
        i=0
        while i<len(prices):
            while stack and prices[i]<=stack[-1]:
                stack.pop()
            stack.append(prices[i])
            if len(stack)>=2:
                res = max(res, stack[-1]-stack[0])
            i+=1
        return res
```