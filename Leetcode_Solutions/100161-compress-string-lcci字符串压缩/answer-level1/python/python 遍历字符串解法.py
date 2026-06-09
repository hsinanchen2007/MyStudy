```
class Solution(object):
    def compressString(self, S):
        """
        :type S: str
        :rtype: str
        """
        if not S:
            return S
        letter = None
        count = 1
        res = ''
        for char in S:
            if char != letter:
                if letter == None:
                    letter = char
                else:
                    res += letter + str(count)
                    letter = char
                    count = 1
            else:
                count += 1
        res += letter + str(count)
        return res if len(res) < len(S) else S
```
