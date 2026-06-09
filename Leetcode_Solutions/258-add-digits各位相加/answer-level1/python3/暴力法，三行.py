```
from functools import reduce

class Solution:
    def addDigits(self, num: int) -> int:
        while num >= 10:
            num = reduce(lambda x, y: x + y ,map(int, str(num)))
        return num
```
