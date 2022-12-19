```
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        return str(eval('+'.join([num1,num2])))
```