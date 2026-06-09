111
``
```
class Solution(object):
    def balancedStringSplit(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        count_L = 0
        count_R = 0
        
        for s_ in s:
            if s_ == 'L':
                count_L += 1
            else:
                count_R += 1
            if count_L == count_R:
                count += 1
        return count


```
时间复杂度O（n），空间复杂度O（1）