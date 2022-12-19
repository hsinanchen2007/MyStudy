```
class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        result = str(num)
        temp = 0
        while len(result) > 1:
            for i in result:
                temp += int(i)
            result = str(temp)
            temp = 0
        return result
```
