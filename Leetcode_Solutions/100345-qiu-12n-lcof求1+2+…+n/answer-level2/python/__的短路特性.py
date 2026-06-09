也可以用||的短路特性，原理和&&一样
```
class Solution:
    def sumNums(self, n: int) -> int:
        return not(n-1) or n+self.sumNums(n-1)
```
