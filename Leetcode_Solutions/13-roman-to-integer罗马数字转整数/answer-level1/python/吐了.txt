### 解题思路


### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        I = 1
        V = 5
        X = 10
        L = 50
        C = 100
        D = 500
        M = 1000
        b = 0
        a = list(s)
        for i in range(len(a)):
            b = eval(a[i]) + b
            if a[i] == 'C' and i != len(a)-1 and a[i+1] == 'M':
                b = b - 200
        
            if a[i] == 'C' and i != len(a)-1 and a[i+1] == 'D':
                b = b - 200
        
            if a[i] == 'X' and i != len(a)-1 and a[i+1] == 'C':
                b = b - 20
        
            if a[i] == 'X' and i != len(a)-1 and a[i+1] == 'L':
                b = b - 20
        
            if a[i] == 'I' and i != len(a)-1 and a[i+1] == 'X':
                b = b - 2
        
            if a[i] == 'I' and i != len(a)-1 and a[i+1] == 'V':
                b = b - 2
        return b
```