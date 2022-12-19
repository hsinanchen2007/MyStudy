```
class Solution(object):
    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        line = 1
        result = 0
        for i in S:
            num = ord(i) - 97
            result += widths[num]
            if result > 100:
                result = 0 + widths[num]
                line += 1
            if result == 100:
                result = 0
                line += 1
        return[line,result]
```
