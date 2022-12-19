```
class Solution(object):
    def removeDuplicates(self, S):
        """
        :type S: str
        :rtype: str
        """
        result = '1'
        for item in S:

            if item == "":
                result+=item
            elif item == result[-1]:
                result = result[:-1]
            else:
                result+=item

        return result[1:]
```
