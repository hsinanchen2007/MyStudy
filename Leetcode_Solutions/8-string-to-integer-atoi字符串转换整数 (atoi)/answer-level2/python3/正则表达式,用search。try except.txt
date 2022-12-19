```
class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        try:
            return max(min(int(re.search(r'^[+-]?\d+', str.lstrip()).group()),2**31-1),-2**31)
        except AttributeError:
            return 0
        # return max(min(int(re.search('^[\+\-]?\d+', str.lstrip()).group()), 2**31 - 1), -2**31)
```
