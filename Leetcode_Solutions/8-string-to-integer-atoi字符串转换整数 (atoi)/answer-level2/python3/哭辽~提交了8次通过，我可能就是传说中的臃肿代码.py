### 解题思路
此处撰写解题思路

### 代码

```python3
INT_MAX = 2 ** 31 - 1
INT_MIN = -2 ** 31

class Solution:
    def myAtoi(self, str: str) -> int:
        nums = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        signs = ['+', '-']
        res, str, count = [0, ''], str.strip(), 0
        for i in str:
            if (count > 0 and i not in nums) or (i not in nums and i not in signs):
                break
            if i in nums:
                res[0] = res[0] * 10 + int(i)
            if res[0] == 0 and res[1] == '' and i in signs:
                res[1] = i
            count += 1  
        if res[1] == '-':
            res[0] = -res[0]
        else:
            res[1] = '+'
        res[0] = min(res[0], INT_MAX) if res[1] == '+' else max(res[0], INT_MIN)
        return res[0]
```