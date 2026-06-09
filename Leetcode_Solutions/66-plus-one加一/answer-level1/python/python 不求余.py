```
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        d = digits[-1] + 1
        if d != 10:
            digits[-1] = d
            return digits

        i = len(digits) - 1
        while i >= 0 :
            if digits[i] == 9:
                digits[i] = 0
            else:
                digits[i] = digits[i] + 1
                return digits
            i -= 1
        return [1] + digits
```
