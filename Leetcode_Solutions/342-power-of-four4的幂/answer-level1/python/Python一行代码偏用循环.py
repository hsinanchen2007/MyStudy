```
class Solution(object):
    def isPowerOfFour(self, num):
        return True if num in [1<<i for i in range(0, 32, 2)] else False
```
