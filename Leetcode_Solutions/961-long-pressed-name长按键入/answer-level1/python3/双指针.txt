
```
class Solution(object):
    def isLongPressedName(self, name, typed):
        """
        :type name: str
        :type typed: str
        :rtype: bool
        """
        a = 0
        b = 0
        while a < len(name) and b < len(typed):
            if name[a] == typed[b]:
                a += 1
                b += 1
            else:
                if a > 0 and typed[b] == name[a - 1]:
                    b += 1
                else:
                    return False
        if a == len(name):
            return True
        else:
            return False
```
