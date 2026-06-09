```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1
        for i in range(len(digits)-1, -1, -1):
            # print(digits[i], carry)
            if digits[i] == 9:
                if carry == 1:
                    digits[i] = 0
                    carry = 1
            else:
                digits[i] += carry
                carry = 0
        if carry == 1: digits = [1] + digits
        return digits
```
