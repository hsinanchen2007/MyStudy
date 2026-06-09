```python
class Solution:
    def myAtoi(self, str: str) -> int:
        # discard whitespace
        # initial plus or minus sign
        # as many numerical digits as possible
        # invalid str return zero
        # -2 ** 31 <= val < 2 ** 31
        

        str = str.lstrip(' ')
        num, flag = '', 0
        for s in str:
            if s == '-' or s == '+' :
                if flag == 0 and num == '':# special case "0-1" "--0"
                    num += s
                    flag = 1
                else:break
            elif s.isdigit(): num += s
            else: break
        if num == '' or num == '-' or num == '+': return 0
        integer_val = int(num)
        return max(-2 ** 31, min(2 ** 31 - 1, integer_val))
```