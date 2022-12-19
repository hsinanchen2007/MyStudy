```
class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        result = []
        temp = 0
        for num in A:
            temp = temp * 2 + num
            result.append(temp % 5 == 0)
        return result
```
