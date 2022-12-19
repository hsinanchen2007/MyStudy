```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits),0,-1):
            digits[i - 1] += 1
            digits[i - 1] = digits[i - 1] % 10
            if digits[i - 1] != 0:
                return digits;
        digits = [1] + digits
        return digits
```
