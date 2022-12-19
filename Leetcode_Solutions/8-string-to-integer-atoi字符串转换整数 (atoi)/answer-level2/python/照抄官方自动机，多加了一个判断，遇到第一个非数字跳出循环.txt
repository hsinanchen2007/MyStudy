### 解题思路
照抄官方自动机，多加了一个判断，遇到第一个非数字跳出循环，不知道这样有没有必要？请大家指点。

### 代码

```python3
class Automation:
    def __init__(self):
        self.state = 'start'
        self.sign = 1
        self.ans = 0
        self.table = {
            'start': ['start', 'signed', 'number', 'end'],
            'signed':['end',   'end',    'number', 'end'],
            'number':['end',   'end',    'number', 'end'],
            'end':   ['end',   'end',    'end',    'end'],
        }
    
    def getcol(self, c):
        if c.isspace():
            return 0
        elif c == '+' or c == '-':
            return 1
        elif c.isdigit():
            return 2
        else:
            return 3
    
    def get(self, c):
        self.state = self.table[self.state][self.getcol(c)]
        if self.state == 'number':
            self.ans = self.ans*10 + int(c)
            self.ans = min(self.ans, 2**31-1) if self.sign == 1 else min(self.ans, 2**31)
        elif self.state == 'signed':
            self.sign = 1 if c == '+' else -1

class Solution:
    def myAtoi(self, str: str) -> int:
        autom = Automation()
        for c in str:
            autom.get(c)
            if autom.state == 'end':
                break
        return autom.sign*autom.ans
```