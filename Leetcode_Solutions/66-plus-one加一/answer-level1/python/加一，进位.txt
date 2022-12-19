![image.png](https://pic.leetcode-cn.com/864dca9538924747042288d4256dc87a2b32158b1a67c5f82651987dd2454205-image.png)

```
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        i = len(digits) - 1
        while i >= 0:
            digits[i] += 1
            if digits[i] % 10 != 0: 
                return digits
            else: 
                digits[i] = 0
                i -= 1
            
        if digits[0] % 10 == 0: return [1] + digits
        return digits
```