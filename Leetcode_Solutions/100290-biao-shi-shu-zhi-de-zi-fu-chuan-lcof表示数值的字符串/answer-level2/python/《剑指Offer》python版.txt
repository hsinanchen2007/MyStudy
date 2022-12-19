### 解题思路
《剑指Offer》python3版，书上是c++版本的

### 代码

```python3
class Solution:
    def __init__(self):
        self.p = 0
    
    def isNumber(self, s: str) -> bool:
        s = s.strip()
        if s == '': return False
        number = self.scanInterger(s)
        
        if self.p > len(s)-1:
            return number

        if self.p < len(s) and s[self.p] == '.':
            self.p += 1
            if self.p > len(s)-1:
                return number
            number = self.scanUnsignedInterger(s) or number

        if self.p < len(s) and s[self.p] in ['e','E']:
            self.p += 1
            if self.p > len(s)-1:
                return False
            number=  number and self.scanInterger(s)

        if self.p < len(s):
            return False

        return number

    def scanInterger(self,s):
        if s[self.p] in ['+','-']:
            self.p += 1
        return self.scanUnsignedInterger(s)

    def scanUnsignedInterger(self,s):
        pre = self.p
        while(self.p < len(s) and s[self.p]>='0' and s[self.p]<='9'):
            self.p += 1
        return self.p > pre
```