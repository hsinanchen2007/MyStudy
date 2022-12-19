
```python []
class Solution:
    def myAtoi(self, str: str) -> int:
        s = str
        n = len(str)
        left = 0
        flag = 1
        for i in range(n):
            if s[i] == ' ':
                continue
            elif s[i] == '+':
                left = i + 1
                flag = 1
                break
            elif s[i] == '-':
                left = i + 1
                flag = -1
                break
            elif '0' <= s[i] <= '9':
                left = i
                break
            else:
                return 0
        num = ''
        for i in range(left, n):
            if '0' <= s[i] <= '9':
                num += s[i]
            else:
                break
        if num == '':
            return 0
        res = int(num) * flag
            
        if res < (-2) ** 31:
            return (-2) ** 31
        if res > 2 ** 31 - 1:
            return 2 ** 31 - 1
        return res
```

