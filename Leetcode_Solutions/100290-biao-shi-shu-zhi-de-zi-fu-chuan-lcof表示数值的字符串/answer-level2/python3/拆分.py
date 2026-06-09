```python
class Solution:
    def isNumber(self, s: str) -> bool:
        s = s.strip()
        if not s: return False
        
        def scan_unsigned_integer(i):
            j = i 
            while i < len(s) and s[i].isdigit():
                i += 1
            return  i > j, i  
        
        def scan_integer(i):
            if i == len(s): return False, i
            if s[i] == '+' or s[i] == '-':
                i += 1
            return scan_unsigned_integer(i)

        numeric, i = scan_integer(0)

        if i < len(s) and s[i] == '.':
            ans, i = scan_unsigned_integer(i+1)
            numeric = numeric or ans 

        if i < len(s) and s[i].lower() == 'e':
            ans, i = scan_integer(i+1)
            numeric = numeric and ans 

        return numeric and i == len(s)

```