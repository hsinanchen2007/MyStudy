```
class Solution:
    def minArray(self, numbers: List[int]) -> int:
        min_val = numbers[0]
        for i in numbers:
            if i < min_val:
                min_val = i
        return min_val
```
