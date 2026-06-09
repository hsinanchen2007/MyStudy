### 解题思路
纯字符串解法，感觉好复杂，还是去看官方题解吧

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        s = str.lstrip()
        if s == '' or s == '-' or s == '+':
            return 0
        num = ['0','1','2','3','4','5','6','7','8','9']
        res = ''
        neg = 1
        if s[0] == '-':
            if s[1] == '-' or s[1] == '+':
                return 0
            neg = -1
            s = s[1:]
        if s[0] == '+':
            if s[1] == '-' or s[1] == '+':
                return 0
            neg = 1
            s = s[1:]
        
        if s[0] not in num:
            return 0
       
        for i in s:
            if i in num:
                res += i
            else:
                break
        res = int(res) * neg
        res = -2 ** 31 if res < -2**31 else res
        res = 2 ** 31 - 1 if res > 2 ** 31 - 1 else res
        return res
```