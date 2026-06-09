
```
class Solution(object):
    def isLongPressedName(self, name, typed):
        """
        :type name: str
        :type typed: str
        :rtype: bool
        """
        i,j=0,0
        while i<len(name) and j<len(typed):
            if name[i]==typed[j]:
                i+=1
            j+=1
        if i==len(name):
            return True
        else:
            return False
```
