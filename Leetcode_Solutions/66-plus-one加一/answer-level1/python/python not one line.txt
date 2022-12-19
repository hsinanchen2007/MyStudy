```python []
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        r = digits
        n = len(digits)
        i = n - 1
        while i >= 0:
            carry = (1 + digits[i]) // 10
            if carry == 1 and i > 0:
                r[i] = 0
                i -= 1
            elif carry == 1 and i == 0:
                r[i] = 0
                r = [1] + r
                return r
            else:
                r[i] += 1
                return r
```
