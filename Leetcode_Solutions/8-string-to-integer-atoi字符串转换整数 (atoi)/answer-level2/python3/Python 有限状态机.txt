```python
class Solution:
    def myAtoi(self, str: str) -> int:
        INT_MAX = 2147483647
        INT_MIN = 2147483648
        state = 'start'
        ret   = 0
        sign  = 1
        table = {
            'start' :['start','signed', 'in_number', 'end'],
            'signed':['end','end', 'in_number', 'end'],
            'in_number':['end','end', 'in_number', 'end'],
            "end":['end','end', 'end', 'end'],
        }
        def getState(c:str):
            if c.isspace():
                return 0
            if c in ('+', '-'):
                return 1
            if c.isdigit():
                return 2
            return 3
        def update(c:str):
            nonlocal state
            nonlocal ret
            nonlocal sign
            state = table[state][getState(c)]
            if state == 'in_number':
                ret = ret * 10 + int(c)
            if state == 'signed':
                sign = 1 if c == '+' else -1
        for c in str:
            update(c)
            if state == 'end':
                return ret * sign
            if sign == 1  and ret > INT_MAX:
                return INT_MAX
            if sign == -1 and ret > INT_MIN:
                return INT_MIN*-1
        else:
            return ret * sign
```