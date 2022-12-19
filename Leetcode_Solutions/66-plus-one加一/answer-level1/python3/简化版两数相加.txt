```
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        c = 1
        for i in range(len(digits)-1, -1, -1):
            n = digits[i] + c
            if n>=10:
                c = 1
                n = n-10
            else:
                c = 0
            digits[i] = n
        if c>0:
            digits.insert(0,c)
        return digits
```
