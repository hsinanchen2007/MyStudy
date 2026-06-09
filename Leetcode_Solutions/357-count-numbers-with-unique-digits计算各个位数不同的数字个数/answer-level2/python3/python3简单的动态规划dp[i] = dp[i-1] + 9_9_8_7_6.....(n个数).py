### 解题思路
如题目，temp记录后面的数字,dp为当前的值
### 代码

```python3
class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1
        dp = 10
        temp = 9
        for i in range(9,10-n,-1):
            temp = temp * i 
            dp += temp
        return dp
```