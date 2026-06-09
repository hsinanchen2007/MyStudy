### 解题思路
学到了如何用上一个状态和当前字符的表格来更新当前状态的方法
为了便于操作可以建一个新的类做这些变量的更新操作
确实思路会清晰很多，也不容易漏掉情况，代码可读性也很强

### 代码

```python3
INT_MAX = 2**31 - 1
INT_MIN = -2**31

class Automaton:
    def __init__(self):
        self.state = "start"
        self.ans = 0
        self.sign = 1
        self.table = { "start":["start", "signed","number","end"],
                       "signed":["end","end","number","end"],
                       "number":["end","end","number","end"],
                       "end":["end","end","end","end"] }
        
        
    def get_col(self,c):
        if c.isspace():
            return 0
        elif c == "+" or c == "-":
            return 1
        elif c.isdigit():
            return 2
        else:
            return 3
        
    def get(self,c):
        self.state = self.table[self.state][self.get_col(c)]
        if self.state == "number":
            self.ans = self.ans * 10 + int(c)
        if self.state == "signed" and c == "-":
            self.sign = -1
        
    
class Solution:
    def myAtoi(self, str: str) -> int:
        automaton = Automaton()
        for c in str:
            automaton.get(c)
        if automaton.sign == 1:
            return min(INT_MAX,automaton.ans*automaton.sign)
        else:
            return max(INT_MIN,automaton.ans*automaton.sign)
```