```
class Solution:
    def isHappy(self, n: int) -> bool:
        exist, temp = set(), n
        while True:
            if temp == 1: return True
            if temp in exist: return False
            exist.add(temp)
            temp = sum(int(i) **2 for i in str(temp))

```
