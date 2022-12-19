本方法对于全是9的序列，先建一个比原序列digits多一位的空序列num，当原序列digits全是9时，先把空序列num第一位设为1，其余为通过循环设为0，然后return num，对于非全是9的情况，直接在原序列digits上操作，然后return digits

```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num = [0] * (len(digits) + 1)
        i = len(digits) - 1
        while i >= 0:
            if digits[i] == 9:
                digits[i] = 0
                if i == 0:
                    num[0] = 1
                    for j in range(1,len(num)):
                        num[j] = 0
                    return num
                i -= 1
            else:
                digits[i] += 1
                return digits
                break
```
