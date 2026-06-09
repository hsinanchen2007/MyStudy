```
class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            //每次打掉最末位的1
            n = n & (n - 1)
            count += 1
        return count
```
